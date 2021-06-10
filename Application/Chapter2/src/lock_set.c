/* lock_set.c */
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
int lock_set(int fd, int type) {
	struct flock old_lock, lock;
	lock.l_whence = SEEK_SET;
	lock.l_start  = 0;
	lock.l_len		= 0;
	lock.l_type		= type;
	lock.l_pid		= -1;

	// 判断文件是否可以上锁
	fcntl(fd, F_GETLK, &lock);
	if (lock.l_type != F_UNLCK) {
		if (lock.l_type == F_RDLCK) {
			printf("Read lock already set by %d\n", lock.l_pid);
		}
		else if (lock.l_type == F_WRLCK) {
			printf("Write lock already set by %d\n", lock.l_pid);
		}
	}

	// 1_type 可能已被F_GETLK修改过
	lock.l_type = type;

	// 根据不同的type值进行阻塞式上锁
	if ((fcntl(fd, F_SETLKW, &lock)) < 0) {
		printf("Lock failed:type = %d\n", lock.l_type);
		return 1;
	}

	switch(lock.l_type) {
		case F_RDLCK:
			printf("Read lock set by %d\n", getpid());
			break;
		case F_WRLCK:
			printf("Write lock set by %d\n", getpid());
			break;
		case F_UNLCK: {
			printf("Release lock by %d\n", getpid());
			return 1;
		}
		break;
		default:	break;
	}
	return 0;
}

/* lock结构体
struct flock {
        short l_type;
        off_t l_start;
        short l_whence;
				off_t l_len;
        pid_t l_pid;
};
*/
