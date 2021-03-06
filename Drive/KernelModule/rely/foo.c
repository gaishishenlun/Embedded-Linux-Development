/* foo.c */
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>

extern void bar(void);

static int __init vser_init(void) {
	printk("vser_init\n");
	bar();
	return 0;
}

static void __exit vser_exit(void) {
	printk("vser_exit\n");
}

module_init(vser_init);
module_exit(vser_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("HL <gsslorz@gmail.com>");
MODULE_DESCRIPTION("ex3");
