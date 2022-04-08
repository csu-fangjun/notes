.PHONY: all clean

srcs := $(shell find * -type f -name "*.tex" -maxdepth 1)
targets_dvi := $(srcs:%.tex=%.dvi)
targets_svg := $(srcs:%.tex=%.svg)
targets_pdf := $(srcs:%.tex=%.pdf)

all: $(targets_svg) $(targets_pdf)

%.dvi: %.tex
	latex $^

%.svg: %.dvi
	dvisvgm --libgs=/usr/local/Cellar/ghostscript/9.55.0/lib/libgs.dylib --no-fonts $^ $@

%.pdf: %.tex
	latexmk -pdf $<

clean:
	$(RM) $(targets_svg) $(targets_dvi) $(targets_pdf)
	latexmk -C
