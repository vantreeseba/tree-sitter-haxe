##
A tree sitter parser for haxe.

I've only testing this using nvim-treesitter.

## Use

Install nvim-treesitter.  
Clone this repo, and run tree-sitter generate (you may have to install globally).  
Once generated, copy the queries to the nvim-treesitter folder
```sh
cp queries/* ~/.vim/BUNDLERPATH/nvim-treesitter/queries/haxe
```

For example if you're using lazy.nvim run:
```
cp queries/* ~/.local/share/nvim/lazy/nvim-treesitter/queries/haxe
```

You may have to create the haxe folder.

Open nvim, and run TSInstallFromGrammer haxe

This should get you running.

### WTF I still don't get highlighting...
You might have to add the haxe filetype for neovim to be able to associate the grammar to your files.
To do this create the appropriate file with:
```
touch ~/.nvim/filetype.lua
```
And add the following content:
```
vim.filetype.add({
  extension = {
    hx = 'haxe',
  },
})
 ```
### What it looks like / does so far (the color scheme is of course customizeable through the highlights / etc in vim).
![image](https://user-images.githubusercontent.com/316782/117491153-72423080-af35-11eb-95ca-ebe9847ecd4b.png)
