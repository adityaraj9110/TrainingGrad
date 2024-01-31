#include <iostream>
#include <regex>

bool isValidURL(const std::string& url) {
    // Regular expression pattern to match a valid URL
    const std::regex pattern(
        R"((https?://)?([a-zA-Z0-9-]+\.){1,}([a-zA-Z]{2,})(:[0-9]+)?(/[^?\s]*)?(\?[^#\s]*)?(#[^\s]*)?$)");

    // Return true if the URL matches the pattern
    return std::regex_match(url, pattern);
}

int main() {
    std::string url;
    std::cout << "Enter a URL: ";
    std::getline(std::cin, url);

    if (isValidURL(url)) {
        std::cout << "The URL is valid." << std::endl;
    } else {
        std::cout << "The URL is not valid." << std::endl;
    }

    return 0;
}
