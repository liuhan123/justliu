# select 

fd_set reset;
FD_ZERO(&reset)
FD_SET(stdin, &reset)
FD_SET(sockfd, &reset)

//测试描述符是否准备好
FD_ISSET(fd, &reset)

---

在此输入正文




