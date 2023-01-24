# ft_ping

## Socket

네트워크는 소켓으로 관리한다.

- 소켓이라는 단일한 인터페이스로 묶어서 사용.
- 네트워크를 초기화하여 다양한 통신 수단을 사용
- 운영체제의 파일시스템과 연동하여 구성.
- 상위에서 보면 파일처럼 다루어지게된다.
- 소켓에서는 socket()과 bind()라는 시스템콜 함수를 사용.

## Socket의 구현정보

- 정의:
  > 소켓 프로그램에 있어서 로컬호스트에서 실행되는 프로세스와 원격 호스트에서 실행되는 프로세스간에 데이터를 교환하기 위해 요구되는 정보.
- 종류
  > 프로토콜 식별자, 로컬 인터넷주소, 로컬번호, 원격인터넷주소, 원격포트번호로 구성
- 구현
  > 네트워크 드라이터(칩에 위치한 레지스터)는 주소설정, 전송 매개변수 변경, 소통량과 오류통계유지와 같은 상당수의 관리작업을 지원하도록 설계되어야한다.

## socket의 생성

### User

User영역에서의 인터페이스 사용

```c
sys_socket(family, type, potocol);

/*
family : AF_UNIX(localhost), AF_INET(internet), AF_IPX...
*/

/*
type: SOCK_STREAM(TCP), SOCK_DGRAM(UDP), SOCK_RAW(raw...)...
*/

```

### Kernel

kernel영역에서 소켓에해당하는 구조체를 할당하고 생성한다.

```c
socket_create();

->

socket_alloc()

->

struct socket {
    state
    type = SOCKET_STREAM
    flags
    ops = inet_stream_ops
    sk /*struct sock */
    files, inodes,
    nest, wait,
}

->

struct sock {
    family = PF_INET
    prot = tcp_prot
    net_pinfo
    tp_pinfo, socket
    sk_buff
    ...
}


```

## Socket 생성후 소켓 데이터 구조의 흐름

1. socket은 fd(식별자)로 다루어진다.
2. file system에 접근

```c
...
f_dentry
...
f_pos
f_op /* operation : dentry, d_inode로 연결
dentry, d_inode는 일종의 포인터역활 */

```

3. f_op( 추상화된 함수집합)을 통해서, 연결되어있는 소켓구조체의 파일로 접근

```c

struct socket {
    state
    type
    flags
    ops
    files, indoes /* 이곳으로 연결 */
    sk /* struct sock 으로 다시 연결 */
}

```

4. 다시한번 소켓 구조체에 연결

```c

struct sock {
    /* socket info */
    next, prev
    daddr, dport
    ...
    sk_buff /* 구조체  */
}
```

## 데이터 보내기 / 데이터 받기


 
