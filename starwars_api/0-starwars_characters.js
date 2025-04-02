#!/usr/bin/node
const request = require('request');

// Check if movie ID is provided
if (process.argv.length !== 3) {
    console.error('Usage: ./0-starwars_characters.js <movie_id>');
    process.exit(1);
}

const movieId = process.argv[2];
const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}`;

// Get film data
request(filmUrl, (error, response, body) => {
    if (error) {
        console.error('Error:', error);
        return;
    }

    if (response.statusCode !== 200) {
        console.error('Invalid status code:', response.statusCode);
        return;
    }

    const film = JSON.parse(body);
    const characters = film.characters;

    // Function to get character name
    const getCharacterName = (characterUrl, index, array) => {
        request(characterUrl, (error, response, body) => {
            if (error) {
                console.error('Error:', error);
                return;
            }

            if (response.statusCode !== 200) {
                console.error('Invalid status code:', response.statusCode);
                return;
            }

            const character = JSON.parse(body);
            console.log(character.name);

            // Processss next character
            if (index < array.length - 1) {
                getCharacterName(array[index + 1], index + 1, array);
            }
        });
    };

    // Start processing characters sequentially
    if (characters.length > 0) {
        getCharacterName(characters[0], 0, characters);
    }
});