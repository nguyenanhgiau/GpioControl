package com.vat.gpiocontrol;

import android.os.Bundle;
import android.preference.Preference.*;
import android.preference.Preference;
import android.preference.PreferenceFragment;
import android.preference.SwitchPreference;
import android.util.Log;
import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.content.SharedPreferences.OnSharedPreferenceChangeListener;

public class GpioPreferenceFragment extends PreferenceFragment implements SharedPreferences.OnSharedPreferenceChangeListener
{
	private Context mCtx;

	@Override
	public void onCreate(final Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);

		getPreferenceManager().setSharedPreferencesName("gpio_control_parameters");
		addPreferencesFromResource(R.xml.gpio_control_preference);
	}

	@Override
	public void onAttach(Activity activity) {
		super.onAttach(activity);
		mCtx = activity;
    }

	@Override
	public void onResume() {
		super.onResume();

		// Set up a listener whenever a key changes
		mCtx.getSharedPreferences("gpio_control_parameters", 
							Context.MODE_PRIVATE).registerOnSharedPreferenceChangeListener(this);
	}

	@Override
	public void onPause() {
		super.onPause();
		// Unregister the listener whenever a key changes
		mCtx.getSharedPreferences("gpio_control_parameters", 
							Context.MODE_PRIVATE)
			.unregisterOnSharedPreferenceChangeListener(this);
	}

	@Override
	public void onSharedPreferenceChanged(SharedPreferences sharedPreferences, String key)
	{
		Log.i("GpioPreferenceFragment", "Value:" + key);
		boolean value;
 		if (key.equals(getString(R.string.left_led_key))) {
			value = sharedPreferences.getBoolean(getString(R.string.left_led_key), false);
			GpioControl.SetLeftLed(value);
 		} else if(key.equals(getString(R.string.right_led_key))) {
			value = sharedPreferences.getBoolean(getString(R.string.right_led_key), false);
			GpioControl.SetRightLed(value);
		}
	}

}
