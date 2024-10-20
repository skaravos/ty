#!/usr/bin/env bash

set -eo pipefail

_script_dir=$(readlink -f "$(dirname "$0")")

"${_script_dir}/build-in-docker.sh" "$@" "ty/ubuntu-buildtools:18.04" ubuntu18
