##
A tree sitter parser for haxe.

I've only testing this using nvim-treesitter.

If you are getting an error on loading parser after 0.11.x, check config below and ensure you are including "src/scanner.c" in file list for config.

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

Add these snippets to your treesitter config or anywhere in your `init.lua`:

This enables and ensures the parser is installed, and that highlight is enabled.
```
local configs = require "nvim-treesitter.configs"
configs.setup {
  ensure_installed = { "haxe" }, -- Install the Haxe parser
  highlight = {
    enable = true,              -- false will disable the whole extension
    additional_vim_regex_highlighting = false,
  },
}
```

```
local parser_config = require "nvim-treesitter.parsers".get_parser_configs()
parser_config.haxe = {
  install_info = {
    url = "https://github.com/vantreeseba/tree-sitter-haxe",
    files = {"src/parser.c", "src/scanner.c"},
    -- optional entries:
    branch = "main",
  },
  filetype = "haxe",
}
```

Open nvim, and run TSInstallFromGrammer haxe

This should get you running.

### I still don't get highlighting...

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
