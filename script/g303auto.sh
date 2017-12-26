#!/bin/bash
#自动设置罗技G303的鼠标速度

fuck=`xinput list |grep -n "Logitech Gaming Mouse G303" |grep -o -E  "^[0-9]+"`
for id in $fuck ;do
	id=`xinput list --id-only | sed -n "$id"p`
	xinput --set-prop $id "Device Accel Velocity Scaling" 1.25
	xinput --set-prop $id "Device Accel Constant Deceleration" 1.4
done
