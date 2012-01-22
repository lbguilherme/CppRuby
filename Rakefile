require 'rake'
require 'rbconfig'
include RbConfig

RUBY_INC = CONFIG['rubyhdrdir']
RUBY_LIB = CONFIG['libdir']
RUBY_LINK = CONFIG['SOLIBS'] + CONFIG['LIBRUBYARG_SHARED']

CXX = CONFIG['CXX']
CXX_FLAGS = "-g -O3 -Wall -Wextra -I. -I#{RUBY_INC} -I#{RUBY_INC}/#{CONFIG['arch']} "

LD = CONFIG['LDSHAREDXX'].sub("$(if $(filter-out -g -g0,#{CONFIG['debugflags']}),,-s)", "")
LD_FLAGS = "#{CONFIG['DLDFLAGS']} #{CONFIG['LDFLAGS']} -L#{RUBY_LIB} #{RUBY_LINK}".sub("$(DEFFILE)", "")

task :default do
  sh "#{CXX} #{CXX_FLAGS} -c test.cpp -o test.o -std=c++0x"
  sh "#{LD} test.o -o test.so #{LD_FLAGS}"
  #sh "#{CXX} #{CXX_FLAGS} -c test2.cpp -o test2.o"
  #sh "#{LD} test2.o -o test2.so #{LD_FLAGS}"
  sh "irb -r./test"
  #sh "ruby -r./test2 -e exit"
end
