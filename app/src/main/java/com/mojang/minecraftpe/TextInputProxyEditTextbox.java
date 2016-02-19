package com.mojang.minecraftpe;

import android.content.Context;
import android.text.InputFilter;
import android.text.Spanned;
import android.util.AttributeSet;
import android.view.KeyEvent;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputConnection;
import android.view.inputmethod.InputConnectionWrapper;
import android.widget.EditText;

public class TextInputProxyEditTextbox extends EditText {
	private MCPEKeyWatcher _mcpeKeyWatcher = null;
	public final int allowedLength;
	public final boolean limitInput;

	public TextInputProxyEditTextbox(Context context, int allowedLength, boolean limitInput) {
		super(context);
		this.allowedLength = allowedLength;
		this.limitInput = limitInput;
		
		if(limitInput) {
			InputFilter[] fillters = new InputFilter[2];
			fillters[0] = new InputFilter.LengthFilter(this.allowedLength);
			fillters[1] = new InputFilter() {
				
				@Override
				public CharSequence filter(CharSequence source, int start, int end, Spanned dest, int dstart, int dend) {
					if(source.equals("") || source.toString().matches("^[a-zA-Z0-9_ -^~\'.,;!#&()=`{}]*")) {
						return source;
					}
					return "";
				}
			};
			setFilters(fillters);
		} else {
			setFilters(new InputFilter[] {new InputFilter.LengthFilter(this.allowedLength)});
		}
	}

	public TextInputProxyEditTextbox(Context context, AttributeSet attrs) {
		super(context, attrs);
		this.allowedLength = 160;
		this.limitInput = false;
	}

	public TextInputProxyEditTextbox(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
		this.allowedLength = 160;
		this.limitInput = false;
	}

	@Override
	public InputConnection onCreateInputConnection(EditorInfo outAttrs) {
		return new MCPEInputConnection(super.onCreateInputConnection(outAttrs), true, this);
	}

	@Override
	public boolean onKeyPreIme(int keyCode, KeyEvent event) {
		if(keyCode == KeyEvent.KEYCODE_BACK && event.getAction() == KeyEvent.ACTION_UP) {
			if(this._mcpeKeyWatcher != null) {
				this._mcpeKeyWatcher.onBackKeyPressed();
			}
			return false;
		}
		return super.onKeyPreIme(keyCode, event);
	}

	public void setOnMCPEKeyWatcher(MCPEKeyWatcher mcpeKeyWatcher) {
		this._mcpeKeyWatcher = mcpeKeyWatcher;
	}

	public interface MCPEKeyWatcher {
		public abstract void onBackKeyPressed();
		public abstract void onDeleteKeyPressed();
	}

	public class MCPEInputConnection extends InputConnectionWrapper {
		TextInputProxyEditTextbox textbox;

		public MCPEInputConnection(InputConnection target, boolean mutable, TextInputProxyEditTextbox textbox) {
			super(target, mutable);
			this.textbox = textbox;
		}

		@Override
		public boolean sendKeyEvent(KeyEvent event) {
			if(this.textbox.getText().length() == 0 && event.getAction() == KeyEvent.ACTION_DOWN && event.getKeyCode() == KeyEvent.KEYCODE_DEL) {
				if(TextInputProxyEditTextbox.this._mcpeKeyWatcher != null) {
					TextInputProxyEditTextbox.this._mcpeKeyWatcher.onDeleteKeyPressed();
				}
				return false;
			}
			return super.sendKeyEvent(event);
		}
	}
}
