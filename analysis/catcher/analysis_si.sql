--  All session_info-based criteria

--  Collect
.read sql/c_01.sql
.read sql/c_02.sql
.read sql/c_03.sql
.read sql/c_04.sql
.read sql/c_05.sql

--  Track
.read sql/t_03.sql
.read sql/t_04.sql

--  Result
DROP VIEW IF EXISTS si;
CREATE VIEW si AS
SELECT
        si.id,
        si.timestamp,
        si.duration/1000 as duration,
        si.mcc,
        si.mnc,
        si.lac,
        si.cid,
        ifnull(c1.score, 0) as c1,
        ifnull(c2.score, 0) as c2,
        ifnull(c3.score, 0) as c3,
        ifnull(c4.score, 0) as c4,
        ifnull(c5.score, 0) as c5,
        ifnull(t3.score, 0) as t3,
        ifnull(t4.score, 0) as t4
FROM session_info as si LEFT JOIN
    c1 ON si.id = c1.id LEFT JOIN
    c2 ON si.id = c2.id LEFT JOIN
    c3 ON si.id = c3.id LEFT JOIN
    c4 ON si.id = c4.id LEFT JOIN
    c5 ON si.id = c5.id LEFT JOIN
    t3 ON si.id = t3.id LEFT JOIN
    t4 ON si.id = t4.id
WHERE si.domain = 0 AND si.mcc > 0 AND si.mnc > 0 AND si.lac > 0 AND si.cid > 0;
