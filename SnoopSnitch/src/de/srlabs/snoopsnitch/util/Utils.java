package de.srlabs.snoopsnitch.util;

import java.io.ByteArrayOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.security.KeyManagementException;
import java.security.KeyStore;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.security.cert.CertificateException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

import javax.net.ssl.HttpsURLConnection;
import javax.net.ssl.SSLContext;
import javax.net.ssl.TrustManagerFactory;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.DialogInterface;
import android.content.DialogInterface.OnCancelListener;
import android.content.DialogInterface.OnClickListener;
import android.telephony.TelephonyManager;
import de.srlabs.snoopsnitch.R;


public class Utils {
	public static HttpsURLConnection openUrlWithPinning(Context context, String strUrl) throws IOException, KeyStoreException, NoSuchAlgorithmException, CertificateException, KeyManagementException{
		URL url = new URL(strUrl);
		HttpsURLConnection connection = (HttpsURLConnection) url.openConnection();
		final InputStream keystoreInputStream = context.getAssets().open("keystore.bks");

		final KeyStore keystore = KeyStore.getInstance("BKS");
		keystore.load(keystoreInputStream, "password".toCharArray());
		keystoreInputStream.close();

		final TrustManagerFactory tmf = TrustManagerFactory.getInstance("X509");
		tmf.init(keystore);

		final SSLContext sslContext = SSLContext.getInstance("TLSv1.2");
		sslContext.init(null, tmf.getTrustManagers(), null);

		// TODO: Handle pinning errors with an appropriate error message/Notification
		connection.setSSLSocketFactory(sslContext.getSocketFactory());
		return connection;
	}

	/**
	 * Generates a new random app ID. Currently the App id consists of 8
	 * hexadecimal digits generated based on the Android SecureRandom class.
	 * 
	 * @return
	 */
	@SuppressLint("TrulyRandom")
	public static String generateAppId(){
		SecureRandom sr = new SecureRandom();
		byte[] random = new byte[4];
		sr.nextBytes(random);
		return String.format("%02x%02x%02x%02x", random[0],random[1],random[2],random[3]);
	}
	public static String formatTimestamp(long millis){
		SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss", Locale.getDefault());
		Date date = new Date(millis);
		return dateFormat.format(date);
	}
	/**
	 * Determines the network generation based on the networkType retrieved via telephonyManager.getNetworkType()
	 * @param networkType
	 * @return
	 * 0: Invalid value
	 * 2: GSM
	 * 3: 3G
	 * 4: LTE
	 */
	public static int networkTypeToNetworkGeneration(int networkType) {
		if (networkType == 0)
			return 0;
		else if (networkType == TelephonyManager.NETWORK_TYPE_UMTS || networkType == TelephonyManager.NETWORK_TYPE_HSDPA
				|| networkType == TelephonyManager.NETWORK_TYPE_HSPA
				|| networkType == TelephonyManager.NETWORK_TYPE_HSPAP
				|| networkType == TelephonyManager.NETWORK_TYPE_HSUPA)
			return 3;
		else if (networkType == TelephonyManager.NETWORK_TYPE_GPRS || networkType == TelephonyManager.NETWORK_TYPE_EDGE
				|| networkType == TelephonyManager.NETWORK_TYPE_CDMA)
			return 2;
		else if(networkType == TelephonyManager.NETWORK_TYPE_LTE){
			return 4;
		} else{
			return 0;
		}
	}

	public static String readFromAssets(Context context, String fileName) throws IOException {

		InputStream inputStream = context.getAssets().open(fileName);
		ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
		int i;
		try {
			i = inputStream.read();
			while (i != -1)
			{
				byteArrayOutputStream.write(i);
				i = inputStream.read();
			}
			inputStream.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return byteArrayOutputStream.toString();
	}
	public static String readFromFileInput(Context context, String fileName) throws IOException {

		InputStream inputStream = context.openFileInput(fileName);
		ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
		int i;
		try {
			i = inputStream.read();
			while (i != -1)
			{
				byteArrayOutputStream.write(i);
				i = inputStream.read();
			}
			inputStream.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return byteArrayOutputStream.toString();
	}

	public static String readFromFileOrAssets(Context context, String fileName) throws IOException {
		String jsonData;
		//  FIXME: Check for file existence - do not use exception for control flow
		try{
			jsonData = readFromFileInput(context, fileName);
		} catch(FileNotFoundException e){
			jsonData = readFromAssets(context, fileName);
		}
		return jsonData;
	}
	public static void showDeviceIncompatibleDialog(Activity activity, String incompatibilityReason, final Runnable callback){
		String dialogMessage =
				activity.getResources().getString(R.string.alert_deviceCompatibility_header) + " " +
						incompatibilityReason + " " +
						activity.getResources().getString(R.string.alert_deviceCompatibility_message);

		MsdDialog.makeFatalConditionDialog(activity, dialogMessage, new OnClickListener()
		{
			@Override
			public void onClick(DialogInterface dialog, int which)
			{
				callback.run();
			}
		}, null,
		new OnCancelListener() {
			@Override
			public void onCancel(DialogInterface dialog) {
				callback.run();
			}
		}, false
				).show();
	}
}
