//reappear bug
#include <openssl/sha.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#ifndef CPPHTTPLIB_OPENSSL_SUPPORT
#define CPPHTTPLIB_OPENSSL_SUPPORT
#endif
#include <httplib.h>#include <iostream>

int main() {
    httplib::Server svr;

    svr.Get("/", [](const httplib::Request &req, httplib::Response &res) {
        // Simple HTML page to manage downloads
        std::string html_page = R"(
            <!DOCTYPE html>
            <html>
            <head>
                <title>Local Download Manager</title>
            </head>
            <body>
                <h1>Local Download Manager</h1>
                <p>Manage your downloads locally.</p>
                <!-- Add your download management UI here -->
            </body>
            </html>
        )";

        res.set_content(html_page, "text/html");
    });

    // Add more routes for managing downloads, handling uploads, etc.

    std::cout << "Local Download Manager is running on port 8080" << std::endl;
    svr.listen("localhost", 8080); // Start the server on port 8080

    return 0;
}
