/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows 窗口边框大小*/
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows 窗口水平间隙 */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows 窗口垂直间隙 */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge 窗口和屏幕边缘水平间隙 */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge  窗口和屏幕边缘垂直间隙*/
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window 只有一个窗口时是否用间隙 1: 没有 0: 有 */
static const int showbar            = 1;        /* 0 means no bar 是否显示状态栏*/
static const int topbar             = 0;        /* 0 means bottom bar 状态栏显示在顶部还是底部*/
static const char *fonts[]          = { "Source Code Pro:size=12" };
static const char dmenufont[]       = "Source Code Pro:size=12";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
	[SchemeHid]  = { col_cyan,  col_gray1, col_cyan  },
};

/* tagging 标签名字 */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions Mod1Mask: Alt Mod4Mask: Window */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
// 极简应用程序选择器
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };

// 临时的浮动居中终端
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

// 终端
static const char *termcmd[]  = { "st", NULL };

// chromium 浏览器
static const char *browsercmd[]  = { "chromium", NULL };

// poweroff 关机
static const char *poweroffcmd[]  = { "poweroff", NULL };

// reboot 重启
static const char *rebootcmd[]  = { "reboot", NULL };

// ranger 终端文件管理
static const char ranger[] = "ranger";
static const char *rangercmd[] = { "st", "-e", ranger, NULL };

static Key keys[] = {
	// 增加间隙
        { MODKEY|Mod1Mask,              XK_h,      incrgaps,       {.i = +1 } },
        // 缩小间隙
	{ MODKEY|Mod1Mask,              XK_l,      incrgaps,       {.i = -1 } },
        // 增加窗口到屏幕的间隙
	{ MODKEY|Mod1Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } },
        // 缩小窗口到屏幕的间隙
	{ MODKEY|Mod1Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } },
        // 增加窗口之间的间隙
	{ MODKEY|Mod1Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } },
        // 缩小窗口之间的间隙
	{ MODKEY|Mod1Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } },
        // 开启和关闭间隙
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
        // 将窗口间隙重置为默认值
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	// 增加窗口之间水平间隙
        { MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } },
        // 缩小窗口之间水平间隙
	{ MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } },
        // 增加窗口之间垂直间隙
	{ MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } },
        // 缩小窗口之间垂直间隙
	{ MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } },
        // 增加窗口到屏幕水平间隙
	{ MODKEY|Mod1Mask,              XK_y,      incrohgaps,     {.i = +1 } },
        // 缩小窗口到屏幕水平间隙
        { MODKEY|Mod1Mask,              XK_o,      incrohgaps,     {.i = -1 } },
	// 增加窗口到屏幕垂直间隙
        { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } },
	// 缩小窗口到屏幕垂直间隙
        { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } },
	// 全屏窗口
	{ MODKEY,                       XK_f,      fullscreen,     {0} },
	// 临时的浮动居中终端
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
        // ranger
        { MODKEY,                       XK_F3,     spawn,          {.v = rangercmd} },
        // 重启
        { MODKEY|ShiftMask,             XK_r,      spawn,          {.v = rebootcmd} },
        // 关机
        { MODKEY|ShiftMask,             XK_e,      spawn,          {.v = poweroffcmd} },
        // chromium
        { MODKEY,                       XK_F2,     spawn,          {.v = browsercmd } },
        /* modifier                     key        function        argument */
        // 极简应用程序选择器
        { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
        // 终端
        { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
        // 显示 隐藏 状态栏
        { MODKEY,                       XK_b,      togglebar,      {0} },
        // 下一个显示的窗口
        { MODKEY,                       XK_j,      focusstackvis,  {.i = +1 } },
        // 上一个显示的窗口
        { MODKEY,                       XK_k,      focusstackvis,  {.i = -1 } },
        // 下一个窗口（包括隐藏窗口）
	{ MODKEY|ShiftMask,             XK_j,      focusstackhid,  {.i = +1 } },
        // 上一个窗口（包括隐藏窗口）
	{ MODKEY|ShiftMask,             XK_k,      focusstackhid,  {.i = -1 } },
        // 水平窗口
        { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
        // 垂直窗口
        { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
        // 缩小窗口
        { MODKEY,                       XK_h,      setmfact,       {.f = -0.02} },
        // 扩大窗口
        { MODKEY,                       XK_l,      setmfact,       {.f = +0.02} },
        // 将当前选中窗口或者下一个窗口提为主窗口
        { ShiftMask,                    XK_Return, zoom,           {0} },
        // 切换上一次选择的标签
        { MODKEY,                       XK_Tab,    view,           {0} },
        // 关闭当前窗口
        { MODKEY,                       XK_q,      killclient,     {0} },
        // 多窗口模式
        { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
        /*
        // 浮动窗口模式
        { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
        // 单窗口模式
        { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
        // 切换上一次选择的窗口模式
        { MODKEY,                       XK_space,  setlayout,      {0} },
        */
        //
        { MODKEY,                       XK_space,  togglefloating, {0} },
        // 选择全部标签
        { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
        // 当前窗口同步到全部标签
        { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
        { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
        { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
        { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
        { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
        // 显示当前窗口
	{ MODKEY|ShiftMask,             XK_s,      show,           {0} },
        // 隐藏当前窗口
	{ MODKEY|ShiftMask,             XK_h,      hide,           {0} },
	TAGKEYS(                        XK_1,                      0)
        TAGKEYS(                        XK_2,                      1)
        TAGKEYS(                        XK_3,                      2)
        TAGKEYS(                        XK_4,                      3)
        TAGKEYS(                        XK_5,                      4)
        TAGKEYS(                        XK_6,                      5)
        TAGKEYS(                        XK_7,                      6)
        TAGKEYS(                        XK_8,                      7)
        TAGKEYS(                        XK_9,                      8)
        // 退出 dwm
        { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

