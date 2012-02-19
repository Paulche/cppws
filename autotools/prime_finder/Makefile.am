bin_PROGRAMS = fixture_comp test

fixture_comp_SOURCES = src/fixture-comp/main.cpp src/prime-finder/Chunk.cpp src/prime-finder/ChunkFactory.cpp src/prime-finder/Finder.cpp
fixture_comp_LDADD = -L/usr/local/lib -lyaml-cpp
fixture_comp_CXXFLAGS = -I/usr/local/include 

test_SOURCES = src/test/main.cpp src/prime-finder/Chunk.cpp src/prime-finder/ChunkFactory.cpp src/prime-finder/Finder.cpp
test_LDADD = -L/usr/local/lib -lyaml-cpp -lgtest -lpthread
test_CXXFLAGS = -I/usr/local/include
