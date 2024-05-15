#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

static char *my_file_path = NULL;
static int new_length = 0;

module_param(my_file_path, charp, S_IRUGO); // \u041f\u0443\u0442\u044c \u043a \u0444\u0430\u0439\u043b\u0443
module_param(new_length, int, S_IRUGO);  // \u041d\u043e\u0432\u0430\u044f \u0434\u043b\u0438\u043d\u0430 \u0444\u0430\u0439\u043b\u0430

static int __init truncate_file_init(void) {
    struct file *filp;
    loff_t pos;
    int ret = 0;

    if (!my_file_path || new_length <= 0) {
        printk(KERN_ERR "File path or length not provided.\n");
        return -EINVAL;
    }

    filp = filp_open(my_file_path, O_RDWR, 0);
    if (IS_ERR(filp)) {
        printk(KERN_ERR "Failed to open file: %s\n", my_file_path);
        return PTR_ERR(filp);
    }

    pos = new_length;
    ret = vfs_truncate(&filp->f_path, pos);
    if (ret) {
        printk(KERN_ERR "Failed to truncate file: %s\n", my_file_path);
        goto out;
    }

    printk(KERN_INFO "File truncated successfully: %s\n", my_file_path);

out:
    filp_close(filp, NULL);
    return ret;
}

static void __exit truncate_file_exit(void) {
    printk(KERN_INFO "File truncate module unloaded.\n");
}

module_init(truncate_file_init);
module_exit(truncate_file_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("binoll");
MODULE_DESCRIPTION("A kernel module to truncate a file to a specified length");

