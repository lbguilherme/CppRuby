require 'rake'
require 'rbconfig'
include RbConfig

RUBY_INC = CONFIG['rubyhdrdir']
RUBY_LIB = CONFIG['libdir']
RUBY_LINK = CONFIG['SOLIBS'] + CONFIG['LIBRUBYARG_SHARED']

CXX = CONFIG['CXX']
CXX_FLAGS = "-std=c++0x -O3 -Wall -Wextra -I#{RUBY_INC} -I#{RUBY_INC}/#{CONFIG['arch']} "

task :default do
  sh "#{CXX} #{CXX_FLAGS} -c ruby.cpp -o ruby.o"
end
