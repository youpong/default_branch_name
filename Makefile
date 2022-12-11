PROJECT = playground
VERSION = 0.0.1

TOPTARGETS := all clean check format docs
SUBDIRS := src
.PHONY: $(TOPTARGETS) $(SUBDIRS)

$(TOPTARGETS): $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@ -j $(MAKECMDGOALS)

clean:
	rm -rf docs

docs:
	doxygen
