DEBUG=0
CLEAN=0

while getopts "cd" arg;do
  case $arg in 
  c)
    CLEAN=1
    ;;
  d)
    DEBUG=1
    ;;
  \?)
    echo "unkown argument"
    ;;
  esac
done

if [ $CLEAN -eq 1 ]; then
  rm build -rf
fi

# create build dir
if [ ! -d build ];
  then cmake -G Ninja -B build
fi

ninja -C build/ -j4

if [ $DEBUG -eq 1 ];then
  (alacritty --config-file ~/.config/alacritty/alacritty_debug.yml -e tmuxinator tm_cppdebug ) &
  sleep 0.2
  (alacritty -e lldb ../runner/tprpix ) &
else
  build/runner/tprpix &
fi

wait
