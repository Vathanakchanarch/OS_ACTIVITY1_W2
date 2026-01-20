#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int src_fd, dest_fd;
    char buffer[1024];
    ssize_t bytes_read;

    // Open source file
    src_fd = open("result.txt", O_RDONLY);
    if (src_fd < 0) {
        return 1;
    }

    // Open or create destination file
    dest_fd = open("copyresult.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        close(src_fd);
        return 1;
    }

    // Copy file content
    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        write(dest_fd, buffer, bytes_read);
    }

    // Close files
    close(src_fd);
    close(dest_fd);

    return 0;
}
