if v:progname =~? "evim"
  finish
endif
set nocompatible

filetype off                   " required!
 
set rtp+=~/.vim/bundle/vundle/
call vundle#rc()
 
" let Vundle manage Vundle
" " required!
Bundle 'gmarik/vundle'
"  
"  " My Bundles here:
"  "
"  " original repos on github
"  Bundle 'tpope/vim-fugitive'
"  Bundle 'Lokaltog/vim-easymotion'
"  Bundle 'rstacruz/sparkup', {
"  'rtp': 'vim/'}
"  Bundle 'tpope/vim-rails.git'
"  " vim-scripts repos
Bundle 'L9'
Bundle 'FuzzyFinder'
"  " non github repos
Bundle 'git://git.wincent.com/command-t.git'
Bundle 'https://github.com/Lokaltog/vim-powerline.git'
Bundle 'Valloric/YouCompleteMe'
"  " ...
"   
filetype plugin indent on     " required!
let g:ycm_global_ycm_extra_conf = '~/.ycm_extra_conf.py'   
let g:ycm_confirm_extra_conf=0   
let g:ycm_collect_identifiers_from_tag_files = 1 "使用ctags生成的tags文件
"
"   " Brief help  -- 此处后面都是vundle的使用命令
"   " :BundleList          - list configured bundles
"   " :BundleInstall(!)    - install(update) bundles
"   " :BundleSearch(!) foo - search(or refresh cache first) for foo
"   " :BundleClean(!)      - confirm(or auto-approve) removal of unused
"   bundles
"   "
"   " see :h vundle for more details or wiki for FAQ
"   " NOTE: comments after Bundle command are not allowed.."""""""""""''"''''"''''''
"  }''''''"""''""""
"启用Vim的特性，而不是Vi的（必须放到配置的最前边） 
" 设置编码  
set encoding=utf-8  
set fenc=utf-8  
set fileencodings=ucs-bom,utf-8,cp936,gb2312,gb18030,big5   
"显示行号 
set number  
" vim-powerline插件
set laststatus=2
set t_Co=256
let g:Powerline_symbols='unicode'
"设置默认打开窗口大小 
set lines=50 columns=100

"隐藏工具栏和滑动条 
set guioptions=aAce  

"设置语法高亮 
if &t_Co > 2 || has("gui_running") 
syntax on 
endif
set number
" 括号自动生成
":inoremap ( ()<esc>i
":inoremap ) <c-r>=ClosePair(')')<cr>
":inoremap [ []<esc>i
":inoremap ] <c-r>=ClosePair(']')<cr>
":inoremap " ""<esc>i
":inoremap ' ''<esc>i
function! ClosePair(char)
if getline('.')[col('.') - 1] == a:char
return "\<right>"
else
return a:char
endif
endfunction 
map <C-c> y
map <C-x> d
map <C-a> <esc>ggVG
imap <S-Space> <ESC>
"------------------------------------------------------------------------------- 
"	 文本操作设置 "------------------------------------------------------------------------------- 
set showtabline=2
set go=aAce

"设置字体 
set gfn=Menlo:h13  
"设置自动缩进 
"设置智能缩进 
set tabstop=4 
set shiftwidth=4 
set softtabstop=4 
set expandtab 
set smarttab

"设置自动换行 
set wrap  
"设置Insert模式和Normal模式下Left和Right箭头键左右移动可以超出当前行 
set whichwrap=b,s,<,>,[,]  
"设置光标移动到屏幕之外时，自动向右滚动10个字符 
set sidescroll=10
"设置窗口透明度 set transparency=10

"在Insert模式下，设置Backspace键如何删除光标前边的字符。这里三个值分别表示空白字符，分行符和插入模式之 
set backspace=indent,eol,start

"打开搜索高亮 
set hlsearch  
"忽略大小写 
set ignorecase  
"在查找时输入字符过程中就高亮显示匹配点。然后回车跳到该匹配点。 
set incsearch	
" allow backspacing over everything in insert mode
set backspace=indent,eol,start

if has("vms")
  set nobackup		" do not keep a backup file, use versions instead
else
  set backup		" keep a backup file (restore to previous version)
  set undofile		" keep an undo file (undo changes after closing)
endif
set history=50		" keep 50 lines of command line history
set ruler		" show the cursor position all the time
set showcmd		" display incomplete commands
set incsearch		" do incremental searching

" For Win32 GUI: remove 't' flag from 'guioptions': no tearoff menu entries
" let &guioptions = substitute(&guioptions, "t", "", "g")

" Don't use Ex mode, use Q for formatting
map Q gq

" CTRL-U in insert mode deletes a lot.  Use CTRL-G u to first break undo,
" so that you can undo CTRL-U after inserting a line break.
inoremap <C-U> <C-G>u<C-U>

" In many terminal emulators the mouse works just fine, thus enable it.
if has('mouse')
  set mouse=a
endif

" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if &t_Co > 2 || has("gui_running")
  syntax on
  set hlsearch
endif

" Only do this part when compiled with support for autocommands.
if has("autocmd")

  " Enable file type detection.
  " Use the default filetype settings, so that mail gets 'tw' set to 72,
  " 'cindent' is on in C files, etc.
  " Also load indent files, to automatically do language-dependent indenting.
  filetype plugin indent on

  " Put these in an autocmd group, so that we can delete them easily.
  augroup vimrcEx
  au!

  " For all text files set 'textwidth' to 78 characters.
  autocmd FileType text setlocal textwidth=78

  " When editing a file, always jump to the last known cursor position.
  " Don't do it when the position is invalid or when inside an event handler
  " (happens when dropping a file on gvim).
  " Also don't do it when the mark is in the first line, that is the default
  " position when opening a file.
  autocmd BufReadPost *
    \ if line("'\"") > 1 && line("'\"") <= line("$") |
    \   exe "normal! g`\"" |
    \ endif

  augroup END

else

  set autoindent		" always set autoindenting on

endif " has("autocmd")

colo apprentice
"colo monokai"
"colo spacegray
""colo jellybeans
"colo autumn2
"colo dante 
set guifont=Menlo:h13
"set transparency=20
:autocmd BufEnter * call DoWordComplete()

nnoremap <silent> <nt> :NERDTree<CR>
vmap "+y :w !pbcopy<CR><CR> 
nmap "+p :r !pbpaste<CR><CR>
"进行版权声明的设置
"添加或更新头
map <F4> :call TitleDet()<cr>'s
function AddTitle()
    call append(0,"/*=============================================================================")
    call append(1,"*")
    call append(2,"* Author: daisy")
    call append(3,"*")
    call append(4,"* Last modified: ".strftime("%Y-%m-%d %H:%M"))
    call append(5,"*")
    call append(6,"* Filename: ".expand("%:t"))
    call append(7,"*")
    call append(8,"* Description: ")
    call append(9,"*")
    call append(10,"=============================================================================*/")
    call append(11,"#include <cstdio>")
    call append(12,"#include <cstring>")
    call append(13,"#include <iostream>")
    call append(14,"#include <algorithm>")
    call append(15,"")
    call append(16,"using namespace std;")
    echohl WarningMsg | echo "Successful in adding the copyright." | echohl None
endf
"更新最近修改时间和文件名
function UpdateTitle()
    normal m'
    execute '/# *Last modified:/s@:.*$@\=strftime(":\t%Y-%m-%d %H:%M")@'
    normal ''
    normal mk
    execute '/# *Filename:/s@:.*$@\=":\t\t".expand("%:t")@'
    execute "noh"
    normal 'k
    echohl WarningMsg | echo "Successful in updating the copy right." | echohl None
endfunction
"判断前10行代码里面，是否有Last modified这个单词，
"如果没有的话，代表没有添加过作者信息，需要新添加；
"如果有的话，那么只需要更新即可
function TitleDet()
    let n=1
    "默认为添加
    while n < 10
        let line = getline(n)
        if line =~ '^\#\s*\S*Last\smodified:\S*.*$'
            call UpdateTitle()
            return
        endif
        let n = n + 1
    endwhile
    call AddTitle()
endfunction

func! CompileGcc()
    exec "w"
    let compilecmd="!gcc "
    let compileflag="-o %< "
    if search("mpi\.h") != 0
        let compilecmd = "!mpicc "
    endif
    if search("glut\.h") != 0
        let compileflag .= " -lglut -lGLU -lGL "
    endif
    if search("cv\.h") != 0
        let compileflag .= " -lcv -lhighgui -lcvaux "
    endif
    if search("omp\.h") != 0
        let compileflag .= " -fopenmp "
    endif
    if search("math\.h") != 0
        let compileflag .= " -lm "
    endif
    exec compilecmd." % ".compileflag
endfunc
func! CompileGpp()
    exec "w"
    let compilecmd="!g++ "
    let compileflag="-o %< "
    if search("mpi\.h") != 0
        let compilecmd = "!mpic++ "
    endif
    if search("glut\.h") != 0
        let compileflag .= " -lglut -lGLU -lGL "
    endif
    if search("cv\.h") != 0
        let compileflag .= " -lcv -lhighgui -lcvaux "
    endif
    if search("omp\.h") != 0
        let compileflag .= " -fopenmp "
    endif
    if search("math\.h") != 0
        let compileflag .= " -lm "
    endif
    exec compilecmd." % ".compileflag
endfunc

func! RunPython()
        exec "!python %"
endfunc
func! CompileJava()
    exec "!javac %"
endfunc


func! CompileCode()
        exec "w"
        if &filetype == "cpp"
                exec "call CompileGpp()"
        elseif &filetype == "c"
                exec "call CompileGcc()"
        elseif &filetype == "python"
                exec "call RunPython()"
        elseif &filetype == "java"
                exec "call CompileJava()"
        endif
endfunc

func! RunResult()
        exec "w"
        if search("mpi\.h") != 0
            exec "!mpirun -np 4 ./%<"
        elseif &filetype == "cpp"
            exec "! ./%<"
        elseif &filetype == "c"
            exec "! ./%<"
        elseif &filetype == "python"
            exec "call RunPython"
        elseif &filetype == "java"
            exec "!java %<"
        endif
endfunc

map <F5> :call CompileCode()<CR>
imap <F5> <ESC>:call CompileCode()<CR>
vmap <F5> <ESC>:call CompileCode()<CR>

