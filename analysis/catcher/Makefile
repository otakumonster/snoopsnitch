DB ?= ~/MSD/Traces/new_parsed_gsmmap.sqlite

COMMON_GP = \
		unset key; \
        set datafile separator "|"; \
        set terminal pdf; \
        set output "$@"; \
		set grid ytics lc rgb "grey" lw 1 lt 0; \
		set grid xtics lc rgb "grey" lw 1 lt 0;

CIPHER_SQL = \
        DROP view IF EXISTS cs; \
        CREATE VIEW cs AS \
        SELECT count(*) AS count FROM session_info \
        WHERE cipher > 0 AND rat = 0 AND cipher_delta > 0 AND cipher_delta < 10000000; \
        SELECT cipher_delta, (count(*)+0.0)/cs.count AS ratio, cipher \
		FROM session_info, cs \
        WHERE cipher > 0 AND rat = 0 AND cipher_delta > 0 AND cipher_delta < 10000000 \
        GROUP BY cipher_delta \
		HAVING ratio > 0.001 \
        ORDER BY cipher_delta \
		;

AUTH_SQL = \
        DROP view IF EXISTS au; \
        CREATE VIEW au AS \
        SELECT count(*) AS count FROM session_info \
        WHERE auth > 0 AND rat = 0 AND auth_delta > 0; \
        SELECT auth_delta, (count(*)+0.0)/au.count AS ratio, auth FROM session_info, au \
        WHERE auth > 0 AND rat = 0 AND auth_delta > 0 \
        GROUP BY auth_delta \
		HAVING ratio > 0.001 \
        ORDER BY auth_delta \
		;

IMEISV_SQL = \
        DROP VIEW IF EXISTS imeisv; \
        CREATE VIEW imeisv AS \
        SELECT count(*) as count, round(sum(CASE WHEN cmc_imeisv > 0 THEN 1.0 ELSE 0.0 END)/count(*),1) as no_imeisv \
        FROM session_info \
        WHERE rat = 0 AND cipher > 0 AND mcc > 0 AND mnc > 0 \
        GROUP BY mcc, mnc \
        HAVING count > 20; \
        DROP VIEW IF EXISTS tot; \
        CREATE VIEW tot AS select count(*) as count FROM imeisv; \
        SELECT no_imeisv, (count(*)+0.0)/tot.count as ratio \
		FROM imeisv, tot \
		GROUP by no_imeisv \
		;

DURATION_SQL = \
		DROP VIEW IF EXISTS dcount; \
		CREATE VIEW dcount AS SELECT count(*) as d from session_info WHERE duration > 350; \
		SELECT duration/500 AS seconds, (count(*)+0.0)/dcount.d AS ratio, sum(CASE WHEN t_locupd THEN 1.0 ELSE 0.0 END)/dcount.d as locupd \
		FROM session_info, dcount \
		WHERE duration > 350 \
		GROUP BY duration/500 \
		HAVING ratio > 0.001;

REJECT_SQL = \
		SELECT ifnull(causes.text || ' \(' || si.lu_rej_cause || '\)', 'Cause value ' || si.lu_rej_cause) as cause, \
			count(*) AS count, \
			si.lu_rej_cause \
		FROM session_info as si LEFT JOIN causes \
		ON si.lu_rej_cause = causes.cause \
		WHERE t_locupd AND not lu_acc AND lu_rej_cause > 0 \
		GROUP BY lu_rej_cause \
		ORDER BY count DESC;

LU_TYPE_SQL = \
		SELECT \
			lu_type, \
			sum(CASE WHEN not lu_acc THEN 0 ELSE 1 END) as acc_count, \
			sum(CASE WHEN not lu_acc THEN 1 ELSE 0 END) as rej_count \
		FROM session_info \
		WHERE t_locupd AND lu_type < 3 \
		GROUP BY lu_type \
		ORDER BY acc_count + rej_count DESC;

all: catcher_analysis.sql

validate: \
	cipher_times.pdf \
	auth_times.pdf \
	imeisv_rate.pdf \
	duration.pdf \
	lu_reject.pdf \
	lu_type.pdf \
	catcher.txt

catcher_analysis.sql: analysis.sql analysis_ci.sql analysis_si.sql sql/*.sql scripts/resolve_read.pl
	./scripts/resolve_read.pl $< > $@.tmp
	mv $@.tmp $@

catcher.txt: validate.sql
	sqlite3 $(DB) $< > $@.tmp
	mv $@.tmp $@

cipher_times.pdf: SQL     = $(CIPHER_SQL)
cipher_times.pdf: GNUPLOT = set xlabel "Cipher delay [ms]"; \
							plot "$<" using 1:2 with lines;

auth_times.pdf:   SQL     = $(AUTH_SQL)
auth_times.pdf:   GNUPLOT =  set xlabel "Authentication delay [ms]"; \
							plot "$<" using 1:2 with lines;

imeisv_rate.pdf:  SQL     = $(IMEISV_SQL)
imeisv_rate.pdf:  GNUPLOT = set xlabel "Fraction of IMEISV requests in CIPHER MODE COMMAND"; \
							plot "$<" using 1:2 with lines;

duration.pdf:     SQL     = $(DURATION_SQL)
duration.pdf:     GNUPLOT = set xlabel "Session duration [s]"; \
							set key; \
							plot "$<" using 1:2 with lines title "Total", \
								 "$<" using 1:3 with lines title "Location updates";

lu_reject.pdf:	  SQL	  = $(REJECT_SQL)
lu_reject.pdf:    GNUPLOT = set xlabel "Reject causes"; \
							unset grid; \
							set format y "%1.0f"; \
							set style fill solid border -1; \
							set xtics rotate by -45; \
							set style data histograms; \
							plot "$<" using 2:xtic(1) title col, \
							     "" using ($$0-1.0):($$2+2.5):2 with labels;

lu_type.pdf:	  SQL	  = $(LU_TYPE_SQL)
lu_type.pdf:      GNUPLOT = set xlabel "Location update types"; \
							set key; \
							unset grid; \
							set style data histograms; \
							set format y "%1.0f"; \
							set style fill solid border -1; \
							set xtics rotate by -45; \
							plot "$<" using 3:xtic(1) title "Rejected", \
							     "" using 2:xtic(1) title "Accepted"\

%.dat: Makefile
	@echo [SQL] $@.
	@sqlite3 -header $(DB) "$(SQL)" > $@

%.pdf: %.dat Makefile
	@echo [GPL] $@.
	@gnuplot -e '$(COMMON_GP)$(GNUPLOT)'

clean:
	rm -f *.pdf *.tmp *.dat catcher_analysis.sql

.PHONY: clean