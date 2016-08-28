#!/bin/bash

# Update SIMBL and remove possible old or alternate version

function nukeFiles() {
    if [[ -e "$1" ]]; then
        if [[ -f "$1" ]]; then
            rm -v "$1"
        else
            rm -vr "$1"
        fi
    fi
}

function createFolder() {
    if [[ ! -e "$1" ]]; then
        mkdir -pv "$1"
    fi
    chmod 777 "$1"
}

log_dir="$HOME"/Library/"Application Support"/mySIMBL/logs
createFolder "$log_dir"
exec &>"$log_dir"/update.log

cleanupFiles=(
    "/Library/Application Support/SIMBL/SIMBLAgent.app"
    "/Library/LaunchAgents/net.culater.SIMBL.Agent.plist"
    "/System/Library/LaunchAgents/net.culater.SIMBL.Agent.plist"
    "/Library/ScriptingAdditions/SIMBL.osax"
    "/Library/ScriptingAdditions/EasySIMBL.osax"
    "$HOME/Library/Application Support/SIMBL"
    "$HOME/Library/ScriptingAdditions/SIMBL.osax"
    "$HOME/Library/ScriptingAdditions/EasySIMBL.osax"
    "/System/Library/ScriptingAdditions/SIMBL.osax"
)

setupFolders=(
    "/Library/Application Support/SIMBL/Plugins"
    "/Library/Application Support/SIMBL/Plugins (Disabled)"
    "/Library/Application Support/SIMBL"
)

echo "Removing old files"

for i in "${cleanupFiles[@]}"; do
    echo Removing: "$i"
    nukeFiles "$i"
done

echo "Setting up folders"

for i in "${setupFolders[@]}"; do
    echo Setting up: "$i"
    createFolder "$i"
done

echo "Installing SIMBLAgent"

mySIMBL=$(dirname "$0")
cp -vr "$mySIMBL"/SIMBL.osax /System/Library/ScriptingAdditions/
cp -vr "$mySIMBL"/SIMBLAgent.app "/Library/Application Support/SIMBL/"
cp -v "$mySIMBL"/SIMBLAgent.app/Contents/Resources/net.culater.SIMBL.Agent.plist "/Library/LaunchAgents"

echo "Launching Agent"

open -a "/Library/Application Support/SIMBL/SIMBLAgent.app"

echo "Done"
