package com.vat.gpiocontrol;

import android.app.Activity;
import android.preference.PreferenceActivity;
import android.os.Bundle;

public class MainActivity extends PreferenceActivity
{

	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		getFragmentManager().beginTransaction().replace(android.R.id.content, new GpioPreferenceFragment()).commit();
	}

	@Override
	public void onDestroy() {
		super.onDestroy();
	}

}

