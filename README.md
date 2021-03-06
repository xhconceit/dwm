# 我的 dwm 构建

dwm 是一个非常快速, 小巧并使用动态管理窗口的窗口管理器

## 要求

构建 dwm 前, 你需要有 Xlib 头文件

## 安装

编辑 config.mk 来匹配你的本地设置 (dwm 将默认安装在 /usr/local)
之后通过以下命令安装 dwm (必须使用 root 用户):

```shell
make clean install
```

## 自定义补丁

### 打补丁

```shell
patch < [patch file]
```

#### patches

1. autostart

> [autostart](https://dwm.suckless.org/patches/autostart/) dwm 处理程序循环前自动启动 `autostart_blocking.sh` 和 `autostart.sh` 脚本
>> 脚本文件放在 `$XDG_DATA_HOME/dwm`, `$HOME/.local/share/dwm`, `$HOME/.dwm` 文件夹中

2. scratchpad

> [scratchpad](https://dwm.suckless.org/patches/scratchpad/) 添加一个临时的浮动居中终端，可以显示隐藏

3. awesomebar

> [awesomebar](https://dwm.suckless.org/patches/awesomebar/) 状态栏显示多个窗口标题，同时可以显示隐藏窗口

4. fullscreen

> [fullscreen](https://dwm.suckless.org/patches/fullscreen/) 窗口全屏

5. hide vacant tags

> [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/) 隐藏没有窗口的标签

6. noborder

> [noborder](https://dwm.suckless.org/patches/noborder/) 只有一个窗口可见时，删除边框

7. pertag

[pertag](https://dwm.suckless.org/patches/pertag/) 标签的布局相互不影响

8. vanitygaps

> [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/) 窗口之间的间隙

9. viewontag

> [viewontag](https://dwm.suckless.org/patches/viewontag/) 移动窗口时自动跳转标签

10. alpha

> [alpha](https://dwm.suckless.org/patches/alpha/) 半透明状态栏和边框，需要 compton | xcompmgr | picom 安装其中一个才生效

11. restartsig

> [restartsig](https://dwm.suckless.org/patches/restartsig/) 重启 dwm

## APP

+ ranger

> 终端文件管理器

+ picom

> 窗口管理器

+ dmenu

> 极简应用程序选择器

+ st

> 极简终端

+ chromium

> chromium 浏览器

+ alsa-utils

> 声音管理器

+ acpilight

> 亮度管理器

+ scrot

> 截图

## 快捷键

| 键                                      | 说明                                   |
| --------------------------------------- | -------------------------------------- |
| `<super>` + `j`                         | 下一个显示的窗口                       |
| `<super>` + `k`                         | 上一个显示的窗口                       |
| `<super>` + `<Shift>` + `j`             | 下一个窗口（包括隐藏窗口）             |
| `<super>` + `<Shift>` + `k`             | 上一个窗口（包括隐藏窗口）             |
| `<super>` + `<Shift>` + `s`             | 显示当前窗口                           |
| `<super>` + `<Shift>` + `h`             | 隐藏当前窗口                           |
| `<super>` + `h`                         | 缩小窗口                               |
| `<super>` + `l`                         | 扩大窗口                               |
| `<super>` + `q`                         | 退出窗口                               |
| `<super>` + `p`                         | 打开 dmenu                             |
| `<super>` + `<Enter>`                   | 打开终端                               |
| `<super>` + `b`                         | 显示和隐藏状态栏                       |
| `<super>` + `i`                         | 水平窗口                               |
| `<super>` + `d`                         | 垂直窗口                               |
| `<Shift>` + `<Enter>`                   | 将当前选中窗口或者下一个窗口提为主窗口 |
| `<super>` + `<Tab>`                     | 切换标签                               |
| `<super>` + `0`                         | 选择全部标签                           |
| `<super>` + `<Shift>` + `0`             | 将当前窗口同步到全部标签               |
| `<super>` + `1 ~ 9`                     | 切换到指定标签                         |
| `<super>` + `<Shift>` + `q`             | 退出 dwm                               |
| `<super>` + `<F2>`                      | 打开浏览器                             |
| `<super>` + `<F3>`                      | 打开 ranger                            |
| `<super>` + `<Shift>` + `e`             | 关机                                   |
| `<super>` + `<Shift>` + `r`             | 重启                                   |
| `<super>` + `<grave>`                   | 显示和隐藏居中的浮动终端               |
| `<super>` + `f`                         | 全屏窗口                               |
| `<super>` + `<Alt>` + `h`               | 增加间隙                               |
| `<super>` + `<Alt>` + `l`               | 缩小间隙                               |
| `<super>` + `<Shift>` + `<Alt>` + `h`   | 增加窗口到屏幕间隙                     |
| `<super>` + `<Shift>` + `<Alt>` + `l`   | 缩小窗口到屏幕间隙                     |
| `<super>` + `<Ctrl>` + `<Alt>` + `h`    | 增加窗口之间的间隙                     |
| `<super>` + `<Ctrl>` + `<Alt>` + `l`    | 缩小窗口之间的间隙                     |
| `<super>` + `<Alt>` + `0`               | 开启和关闭间隙                         |
| `<super>` + `<Shift>` + `<Alt>` + `0`   | 重置全部间隙                           |
| `<super>` + `y`                         | 增加窗口之间的水平间隙                 |
| `<super>` + `o`                         | 缩小窗口之间的水平间隙                 |
| `<super>` + `<Ctrl>` + `y`              | 增加窗口之间的垂直间隙                 |
| `<super>` + `<Ctrl>` + `o`              | 缩小窗口之间的垂直间隙                 |
| `<super>` + `<Alt>` + `y`               | 增加窗口到屏幕边缘的水平间隙           |
| `<super>` + `<Alt>` + `o`               | 缩小窗口到屏幕边缘的水平间隙           |
| `<super>` + `<Shift>` + `y`             | 增加窗口到屏幕边缘的垂直间隙           |
| `<super>` + `<Shift>` + `o`             | 缩小窗口到屏幕边缘的垂直间隙           |
| `<super>` + `<Ctrl>` + `<Shift>` + `q`  | 重启 dwm                               |
| `<Alt>` + `<F1>`                        | 开关声音                               |
| `<Alt>` + `<F2>`                        | 降低声音                               |
| `<Alt>` + `<F3>`                        | 扩大声音                               |
| `<Alt>` + `<F11>`                       | 减小亮度                               |
| `<Alt>` + `<F12>`                       | 增加亮度                               |
| `<super>` + `s`                         | 截图                                   |

## 运行 dwm

将以下行添加到 .xinitrc 中来通过 `startx` 启动 dwm:

```shell
exec dwm
```
