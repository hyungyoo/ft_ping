# include "./include/ping.h"

int main() {
    int icmp_socket;
    char buffer[1024];
    struct icmp *ptr_icmp;
    struct sockaddr_in addr, from;
    int ret;

/* 
https://stackoverflow.com/questions/27999656/while-creating-raw-socket-error-like-operation-not-permitted 
vm으로 해야하는이유: 원시소켓은 root권한
*/
    icmp_socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (icmp_socket < 0) {
        perror("socket Error\n");
        // exit(0);
    }

    struct icmp test;

    printf("%d is socket icmp fd \n", icmp_socket);
    printf("size of icmp struct: %lu\n", sizeof(test));
    // size는 나중에 조정하기
    // reply는 더 커질수있으니, 다시계산하고 일단 1024 최대값으로
    ft_memset(buffer, 0x00, 1024);

    ft_memset(&test.icmp_data, 'X', 10);
    // test = (struct icmp *)buffer;
    test.icmp_type = ICMP_ECHO;
    test.icmp_code = 0;
    // cksum은?
    test.icmp_cksum = 0;
    // seq는?
    // 요구 패킷순서 : 0부터 시작
    test.icmp_seq = 15;
    // id는?
    test.icmp_id = getpid();

    printf("size of icmp struct: %lu\n", sizeof(test));
    // printf("get data %s", )

    return 0;
}