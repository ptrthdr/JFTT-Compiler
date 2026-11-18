#include <filesystem>
#include <fstream>
#include <iostream>
#include <system_error>

int main(int argc, char* argv[]) {
    if (argc != 3 || argv[1][0] == '\0' || argv[2][0] == '\0') {
        std::cerr << "Usage: " << argv[0] << " <input-file> <output-file>\n";
        return 1;
    }

    const std::filesystem::path input_path(argv[1]);
    std::error_code error;
    const bool regular_file = std::filesystem::is_regular_file(input_path, error);
    if (error || !regular_file) {
        std::cerr << "Error: input must be an accessible regular file: "
                  << input_path << '\n';
        return 1;
    }

    std::ifstream input(input_path, std::ios::binary);
    if (!input.is_open()) {
        std::cerr << "Error: cannot open input file: " << input_path << '\n';
        return 1;
    }

    input.peek();
    if (input.bad() || (input.fail() && !input.eof())) {
        std::cerr << "Error: cannot read input file: " << input_path << '\n';
        return 1;
    }

    std::cerr << "Error: compilation is not implemented yet. "
                 "The output file has not been created or modified: "
              << std::filesystem::path(argv[2]) << '\n';
    return 1;
}
