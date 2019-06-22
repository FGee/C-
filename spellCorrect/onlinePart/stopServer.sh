#!/bin/sh
ps -ef | grep spellCorrectServer.exe | grep -v grep | awk '{print $2}' | xargs kill -10
