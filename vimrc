# vimrc
se sm                                                                     
set ruler
set ts=4 et
se ai                                                                     
se nu                                                                         
set cc=80 
"set tags=      
set tags=~/tag_location
"se bg=dark                                                                     
source ~/.vim/cscope_maps.bin
se ic                    

filetype plugin indent on
# for cscope commands 
# 
map m0 o DEBUG(VFS_EGN_NORECOVER_ERROR, ());<esc>
map m1 o DEBUG(VFS_EGN_RECOVER_ERROR, ());<esc>
map m2 o DEBUG(VFS_EGN_WARNING, ());<esc>
map m3 o DEBUG(VFS_EGN_INFO, ());<esc>                                   
map m4 o DEBUG(VFS_EGN_INTERNAL_DS, ());<esc>
map m5 o DEBUG(VFS_EGN_FULL_PKT, ());<esc>
