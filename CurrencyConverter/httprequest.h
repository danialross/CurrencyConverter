#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <string>
#include <curl/curl.h>

class HttpRequest
{
public:
    HttpRequest();

    ~HttpRequest();

    bool makeGetRequest(const std::string& url, std::string& response);

private:
    CURL* curl;

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
};

#endif // HTTPREQUEST_H
