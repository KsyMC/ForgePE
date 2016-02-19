package com.mojang.android.net;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpDelete;
import org.apache.http.client.methods.HttpEntityEnclosingRequestBase;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.methods.HttpPut;
import org.apache.http.client.methods.HttpRequestBase;
import org.apache.http.conn.ConnectTimeoutException;
import org.apache.http.entity.StringEntity;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpConnectionParams;
import org.apache.http.params.HttpParams;
import org.apache.http.util.EntityUtils;

import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.security.InvalidParameterException;

public class HTTPRequest {
    String mCookieData = "";
    HttpRequestBase mHTTPRequest = null;
    String mRequestBody = "";
    String mRequestContentType = "";
    HTTPResponse mResponse = new HTTPResponse();
    String mURL = "";

    private void addBodyToRequest(HttpEntityEnclosingRequestBase request) {
        if (this.mRequestBody.equals(""))
            return;

        try {
            StringEntity se = new StringEntity(this.mRequestBody);
            se.setContentType(this.mRequestContentType);

            request.setEntity(se);
            request.addHeader("Content-Type", this.mRequestContentType);
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    private void addHeaders() {
        this.mHTTPRequest.addHeader("User-Agent", "MCPE/Android");
        HttpParams httpParameters = new BasicHttpParams();
        HttpConnectionParams.setConnectionTimeout(httpParameters, 3000);
        this.mHTTPRequest.setParams(httpParameters);

        if (this.mCookieData != null && this.mCookieData.length() > 0)
            mHTTPRequest.addHeader("Cookie", mCookieData);

        mHTTPRequest.addHeader("Charset", "utf-8");
    }

    private synchronized void createHTTPRequest(String method) {
        if(method.equals("DELETE")) {
            mHTTPRequest = new HttpDelete(mURL);
        } else if(method.equals("PUT")) {
            HttpPut putRequest = new HttpPut(mURL);
            addBodyToRequest(putRequest);
            mHTTPRequest = putRequest;
        } else if(method.equals("GET")) {
            mHTTPRequest = new HttpGet(mURL);
        } else if(method.equals("POST")) {
            HttpPost postRequest = new HttpPost(mURL);
            addBodyToRequest(postRequest);
            mHTTPRequest = postRequest;
        } else {
            throw new InvalidParameterException("Unknown request method " + method);
        }
    }

    public synchronized void abort() {
        mResponse.setStatus(HTTPResponse.ABORTED);
        if (mHTTPRequest != null)
            mHTTPRequest.abort();
    }

    public HTTPResponse send(String method) {
        createHTTPRequest(method);
        addHeaders();

        if (mResponse.getStatus() == HTTPResponse.ABORTED)
            return mResponse;

        try {
            HttpClient client = HTTPClientManager.getHTTPClient();
            HttpResponse response = client.execute(mHTTPRequest);
            mResponse.setResponseCode(response.getStatusLine().getStatusCode());
            HttpEntity entity = response.getEntity();

            mResponse.setBody(EntityUtils.toString(entity));
            mResponse.setStatus(HTTPResponse.DONE);
            mResponse.setHeaders(response.getAllHeaders());
        } catch (ConnectTimeoutException e) {
            this.mResponse.setStatus(HTTPResponse.TIME_OUT);
        } catch (IOException e) {
            e.printStackTrace();
        }
        this.mHTTPRequest = null;

        return this.mResponse;
    }

    public void setContentType(String conentType) {
        this.mRequestContentType = conentType;
    }

    public void setCookieData(String cookieData) {
        this.mCookieData = cookieData;
    }

    public void setRequestBody(String requestBody) {
        this.mRequestBody = requestBody;
    }

    public void setURL(String url) {
        this.mURL = url;
    }
}
