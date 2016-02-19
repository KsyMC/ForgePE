package com.ksymc.forgepe;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MCPENotFoundActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.mcpenotfound);
		
		Button installBtn = (Button) findViewById(R.id.button_mcpeInstall);
		installBtn.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				Uri buyLink = Uri.parse("market://details?id=com.mojang.minecraftpe");
				startActivity(new Intent("android.intent.action.VIEW", buyLink));
			}
		});
	}
}
