# Chapter5 多线程编程

## 多线程

多线程编程在编译时需添加参数`-pthread`。即：

```bash
$ gcc -o main -pthread main.c
```

### 0x00.线程基本编程

例：thread.c

函数：

- pthread_cteate()
- pthread_exit()
- pthread_join()
- pthread_cancel()

### 0x01.线程之间的同步与互斥(互斥锁/信号量)

例：thread_mutex.c

互斥锁函数：

- pthread_mutex_init()
- pthread_mutex_lock()
- pthread_mutex_trylock()
- pthread_mutex_unlock()
- pthread_mutex_destroy()

信号量函数：

- sem_init()
- sem_wait()
- sem_trywait()
- sem_post()
- sem_getvalue()
- sem_destroy()

### 0x02.线程属性

例：thread_attr.c

函数：

- pthread_attr_init()
- pthread_attr_setscope()
- pthread_attr_setdetachstate()
- pthread_attr_getschedparam()
- pthread_attr_setschedparam()

## 多线程实验

### 生产者-消费者问题

#### 实验内容：

- 有一个有限缓冲区和两个线程：生产者和消费者，它们分别不停地把产品放入缓冲区和从缓冲区中拿走产品。一个生产者在缓冲区满的时候必须等待，一个消费者在缓冲区空的时候也不许等待。另外，因为缓冲区是临界资源，所以生产者和消费者之间必须互斥执行。
- 使用有名管道模拟有限缓冲区，并且使用信号量来解决同步互斥问题。

#### 实验源码：

- producer-customer.c
