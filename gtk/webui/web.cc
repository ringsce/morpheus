#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

const int PORT = 8080;
const int BACKLOG = 10;

std::string read_file(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return "File not found";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

std::string generate_response(const std::string &request) {
    // Parse the request to extract the path
    std::istringstream iss(request);
    std::string line;
    std::getline(iss, line); // Get the first line of the request
    std::vector<std::string> parts;
    std::istringstream line_stream(line);
    std::copy(std::istream_iterator<std::string>(line_stream),
              std::istream_iterator<std::string>(),
              std::back_inserter(parts));

    // Extract the path from the request
    std::string path = "/";
    if (parts.size() > 1) {
        path = parts[1];
    }

    // Generate the response based on the requested path
    if (path == "/") {
        // Serve the index.html file
        return read_file("index.html");
    } else {
        // Serve a 404 page if the requested file is not found
        return "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\n404 Not Found";
    }
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    int opt = 1;

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    std::cout << "HTTP Server is running on port " << PORT << std::endl;

    while (true) {
        // Accept incoming connections
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("accept");
            continue;
        }

        // Read the request
        char buffer[1024] = {0};
        read(client_fd, buffer, 1024);
        std::string request(buffer);

        // Generate the response
        std::string response = generate_response(request);

        // Send the response
        send(client_fd, response.c_str(), response.length(), 0);

        // Close the connection
        close(client_fd);
    }

    return 0;
}
