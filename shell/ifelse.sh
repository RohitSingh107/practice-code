#!/bin/bash

if [ $XDG_SESSION_TYPE = 'wayland' ]
then
    echo "You are on Wayland"
else
    picom --experimental-backends &
    echo "You are on X11"
    fi
