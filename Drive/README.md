# Linux 内核模块开发

## 相关工具

```bash
# insmod vser.ko			# 模块加载

# dmesg								# 查看控制台信息

# depmod							# 更新模块的依赖信息

# modprobe vser				# 模块加载(自动解决依赖、使用前先使用depmod)

# modinfo vser				# 查看模块的信息

# rmmod vser					# 卸载模块

```

- 模块加载时可带参数
- - modprobe vser [参数 1]=[值 1] [参数 2]=[值 2]
