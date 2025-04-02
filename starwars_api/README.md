# Star Wars API

A Node.js project that interacts with the Star Wars API to retrieve and display information about Star Wars movies and characters.

## Description

This project contains scripts that use the Star Wars API (SWAPI) to fetch and display data. The current implementation includes a script that prints all characters from a specific Star Wars movie in the order they appear in the API's character list.

## Requirements

- Ubuntu 14.04 LTS
- Node.js (version 10.14.x)
- Editors: vi, vim, emacs
- All files must be executable
- Code must be semistandard compliant (Standard JS + semicolons)
- All files should end with a new line
- The first line of all files should be exactly `#!/usr/bin/node`

## Installation

### Install Node.js 10.x

```bash
curl -sL https://deb.nodesource.com/setup_10.x | sudo -E bash -
sudo apt-get install -y nodejs
```

### Install Semistandard

```bash
sudo npm install semistandard --global
```

### Install Request Module

```bash
sudo npm install request --global
export NODE_PATH=/usr/lib/node_modules
```

## Usage

### 0-starwars_characters.js

This script prints all characters of a Star Wars movie in the same order as they appear in the API.

```bash
./0-starwars_characters.js <movie_id>
```

Example:
```bash
./0-starwars_characters.js 3
```

Output:
```
Luke Skywalker
C-3PO
R2-D2
Darth Vader
Leia Organa
Obi-Wan Kenobi
Chewbacca
Han Solo
Jabba Desilijic Tiure
Wedge Antilles
Yoda
Palpatine
Boba Fett
Lando Calrissian
Ackbar
Mon Mothma
Arvel Crynyd
Wicket Systri Warrick
Nien Nunb
Bib Fortuna
```

## Files

- `0-starwars_characters.js`: Script that prints all characters of a Star Wars movie.

## Resources

- [Star Wars API Documentation](https://swapi.dev/documentation)
- [Request Module Documentation](https://github.com/request/request)


## Author
BM