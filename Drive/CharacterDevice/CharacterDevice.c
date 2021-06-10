#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>

#define VSER_MAJOR		256
#define VSER_MINOR		0
#define VSER_DEV_CNT	1
#define Vser_DEV_NAME	"MyChar"

static int __init MyChar_init(void){
	int ret;
	dev_t dev;

	dev = MKDEV(VSER_MAJOR, VSER_MINOR);
	ret = register_chrdev_region
}
