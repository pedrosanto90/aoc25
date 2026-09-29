CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -O2

DIST := dist
DAYS := $(patsubst %/,%,$(wildcard day*/))

.PHONY: $(DAYS) clean

$(DAYS):
	@mkdir -p $(DIST)
	$(CXX) $(CXXFLAGS) $@/main.cpp -o $(DIST)/$@
	cd $@ && ../$(DIST)/$@

clean:
	rm -rf $(DIST)
