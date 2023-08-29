#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

class HttpRequest
{
public:
    HttpRequest();

    ~HttpRequest();

    nlohmann::json makeGetRequest(const std::string& url);

private:
    CURL* curl;

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
};

#endif // HTTPREQUEST_H
