#!/bin/bash
#This script will translate only english sentence to Chinese using Google Translate, I use this script in Goldendict so if i want to translate Chinese to English using ChineseToEnglish dictionary, Google Translate Resault won't show up.

if [ $# -eq 1 ]
then
	if [ $(echo "$1" | grep -c -i '[a-zA-z]') -gt 0 ]
	then
		trans -e google -s en -t zh-CN -show-original y -show-original-phonetics n -show-translation y -no-ansi -show-translation-phonetics n -show-prompt-message n -show-languages n -show-original-dictionary n -show-dictionary n -show-alternatives n "$1"
	fi
fi
