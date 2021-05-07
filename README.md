##
A tree sitter parser for haxe.

I've only testing this using nvim-treesitter.

## Use

Install nvim-treesitter.  
Clone this repo, and run tree-sitter generate (you may have to install globally).  
Once generated, copy the queries/highlights.scm to ~/.vim/bundle/nvim-treesitter/queries/haxe/highlights.scm  

Open nvim, and run TSInstallFromGrammer haxe

This should get you running.

### What it looks like / does so far (the color scheme is of course customizeable through the highlights / etc in vim).
![image](https://user-images.githubusercontent.com/316782/117491153-72423080-af35-11eb-95ca-ebe9847ecd4b.png)
