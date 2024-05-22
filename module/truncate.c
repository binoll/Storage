#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/path.h>
#include <linux/namei.h>
#include <linux/mount.h>
#include <linux/file.h>

int truncate_file_no_zero(const char *path, loff_t new_size);

static char *my_file_path = NULL;
static int new_length = 0;

module_param(my_file_path, charp, S_IRUGO);
module_param(new_length, int, S_IRUGO);

int truncate_file_no_zero(const char *path, loff_t new_size) {
	struct path kernel_path;
	struct inode *inode;
	struct iattr new_attrs;
	int error;

	error = kern_path(path, LOOKUP_FOLLOW, &kernel_path);
	if (error) {
		printk(KERN_ERR "Cannot find file: %s\n", path);
		return error;
	}

	inode = d_inode(kernel_path.dentry);
	inode_lock(inode);

	new_attrs.ia_size = new_size;
	new_attrs.ia_valid = ATTR_SIZE;

	error = notify_change(mnt_idmap(kernel_path.mnt), kernel_path.dentry, &new_attrs, NULL);

	inode_unlock(inode);
	path_put(&kernel_path);

	return error;
}

static int __init truncate_file_init(void) {
	struct file *filp;
	int error = 0;

	if (!my_file_path || new_length <= 0) {
		printk(KERN_ERR "File path or length not provided.\n");
		return -EINVAL;
	}

	filp = filp_open(my_file_path, O_RDWR, 0);
	if (IS_ERR(filp)) {
		printk(KERN_ERR "Failed to open file: %s\n", my_file_path);
		return PTR_ERR(filp);
	}

	error = truncate_file_no_zero(my_file_path, new_length);
	if (error) {
		printk(KERN_ERR "Failed to truncate file: %s\n", my_file_path);
		goto out;
	}

	printk(KERN_INFO "File truncated successfully: %s\n", my_file_path);

	out:
	filp_close(filp, NULL);
	return error;
}

static void __exit truncate_file_exit(void) {
	printk(KERN_INFO "File truncate module unloaded.\n");
}

module_init(truncate_file_init);
module_exit(truncate_file_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("binoll");
MODULE_DESCRIPTION("A kernel module to truncate a file to a specified length");
