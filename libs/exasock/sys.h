#ifndef SYS_H_22D9F0DEB4214559B1B05D3BFA116C9F
#define SYS_H_22D9F0DEB4214559B1B05D3BFA116C9F

extern unsigned int             exa_dst_table_size;
extern struct exa_dst_entry *   exa_dst_table;
extern uint8_t *                exa_dst_used_flags;

/* Functions for communicating with the kernel component of Exasock */

void exa_sys_dst_queue(in_addr_t ip_addr, char *hdr, size_t hdr_len,
                       const struct iovec * restrict iov,
                       size_t iovcnt, size_t skip_len, size_t data_len);
int exa_sys_dst_request(in_addr_t dst_addr, in_addr_t *src_addr,
                        int *if_index);

int exa_sys_exasock_open(int native_fd);
int exa_sys_replace_fd(int native_fd, int exasock_fd);

int exa_sys_bind(int fd, struct exa_endpoint * restrict endpoint);
int exa_sys_connect(int fd, struct exa_endpoint * restrict endpoint);
int exa_sys_listen(int fd, struct exa_endpoint * restrict endpoint);
int exa_sys_update(int fd, struct exa_endpoint * restrict endpoint);

struct exa_socket_state;

int exa_sys_buffer_mmap(int fd, struct exa_socket_state **state,
                        char **rx_buf, char **tx_buf);
void exa_sys_buffer_munmap(int fd, struct exa_socket_state **state,
                           char **rx_buf, char **tx_buf);

int exa_sys_setsockopt(int fd, int level, int optname, const void *optval,
                       socklen_t optlen);
int exa_sys_getsockopt(int fd, int level, int optname, void *optval,
                       socklen_t *optlen);

#endif /* SYS_H_22D9F0DEB4214559B1B05D3BFA116C9F */
