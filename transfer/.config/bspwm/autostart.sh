#!/usr/bin/bash

function run {
  if ! pgrep $1 ;
  then
    $@&
  fi
}


#Find out your monitor name with xrandr or arandr (save and you get this line)
#xrandr --output VGA-1 --primary --mode 1360x768 --pos 0x0 --rotate normal
#xrandr --output DP2 --primary --mode 1920x1080 --rate 60.00 --output LVDS1 --off &
#xrandr --output LVDS1 --mode 1366x768 --output DP3 --mode 1920x1080 --right-of LVDS1
#xrandr --output HDMI2 --mode 1920x1080 --pos 1920x0 --rotate normal --output HDMI1 --primary --mode 1920x1080 --pos 0x0 --rotate normal --output VIRTUAL1 --off

dunst &
lxsession &


$HOME/.config/polybar/launch.sh &


#Some ways to set your wallpaper besides variety or nitrogen
#feh --bg-scale ~/.config/bspwm/wall.png &
feh --bg-fill /home/rohit/mydata/Pictures/wallpapers/0051.jpg &
#feh --randomize --bg-fill ~/Képek/*
#feh --randomize --bg-fill ~/Dropbox/Apps/Desktoppr/*


#xsetroot -cursor_name left_ptr &
run sxhkd -c ~/.config/bspwm/sxhkd/sxhkdrc &

run nm-applet &
#numlockx on &
#blueberry-tray &
picom --config $HOME/.config/bspwm/picom.conf &

#run volumeicon &

export QT_QPA_PLATFORMTHEME=qt5ct

emacs --daemon
