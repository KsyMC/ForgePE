package com.mojang.android.net;

import org.apache.http.Header;

public class HTTPResponse {
    public static final int IN_PROGRESS = 0;
    public static final int DONE = 1;
    public static final int ABORTED = 2;
    public static final int TIME_OUT = 3;

    String body = "";
    Header headers[];
    int responseCode = -100;
    int status = 0;

    public String getBody() {
        return body;
    }

    public Header[] getHeaders() {
        return headers;
    }

    public int getResponseCode() {
        return responseCode;
    }

    public int getStatus() {
        return status;
    }

    public void setBody(String newBody) {
        body = newBody;
    }

    public void setHeaders(Header[] newHeaders) {
        headers = newHeaders;
    }

    public void setResponseCode(int newResonseCode) {
        responseCode = newResonseCode;
    }

    public void setStatus(int newStatus) {
        status = newStatus;
    }
}
