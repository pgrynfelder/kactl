set CW='-Wall -Wextra -pedantic -Wshadow -Winit-self -Wformat=2
  -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2
  -Wduplicated-cond -Wcast-qual -Wcast-align'
alias safe-c++='g++ -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
  $CW -g3 -fsanitize=address,undefined -fstack-protector'
alias debug-c++='g++ $CW -g3 -Og'
alias fast-c++='g++ $CW -O3'