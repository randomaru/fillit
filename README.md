# fillit
The aim of this project is to implement algorithm that finds optimal position for tetris pieces called tetrimino. Tetriminos should form as small square as possible.
# Project description
The description of a Tetriminos must respect the following rules :
- Precisely 4 lines of 4 characters, each followed by a new line (4x4 square).
- A Tetrimino is a classic piece of Tetris composed of 4 blocks.
- Each character must be either a block character(’#’ ) or an empty character (’.’).
- Each block of a Tetrimino must touch at least one other block on any of his 4 sides (up, down, left and right).

*Examples of valid tetriminos:*<br>
![Valid](https://github.com/randomaru/fillit/raw/master/img/valid.png)<br>

To identify each Tetrimino in the square solution, we will assign a capital letter to each Tetrimino, starting with ’A’ and increasing for each new Tetrimino. Maximum number of tetriminos in map is 26.

# Test!
Run `make` then run `./fillit` with map from tests directory, for example:<br>

![prog](https://github.com/randomaru/fillit/raw/master/img/prog.png)<br>

**This is a group project.**  

## Authors: 


<ul>
        <li><a href="https://github.com/randomaru">Maria Belyaeva</a></li>
        <li> <a href="https://github.com/Svetlaaanl">Svetlana Fomina</a></li>
</ul>
