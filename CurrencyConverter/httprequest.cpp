#include "httprequest.h"

HttpRequest::HttpRequest() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
}

HttpRequest::~HttpRequest() {
    if (curl) {
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

nlohmann::json HttpRequest::makeGetRequest(const std::string& url) {
    nlohmann::json responseJson;

    if (!curl) {
        return responseJson;;
    }

    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);

    if (res == CURLE_OK) {
        try {
            responseJson = nlohmann::json::parse(response);
        } catch (const nlohmann::json::parse_error& e) {
            std::cerr << "JSON parsing error: " << e.what() << std::endl;
        }
    } else {
        std::cerr << "HTTP request failed: " << curl_easy_strerror(res) << std::endl;
    }

    return responseJson;
}

size_t HttpRequest::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    std::string* buffer = static_cast<std::string*>(userp);
    buffer->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

