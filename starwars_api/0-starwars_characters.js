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

    // Function to fetch and print character name using promises
    const fetchCharacterName = (url) => {
        return new Promise((resolve, reject) => {
            request(url, (error, response, body) => {
                if (error) reject(error);
                else if (response.statusCode !== 200) {
                    reject(new Error(`Status code: ${response.statusCode}`));
                } else {
                    const character = JSON.parse(body);
                    resolve(character.name);
                }
            });
        });
    };

    // Process character URLs one by one in order
    const processCharacters = async (index = 0) => {
        if (index >= characters.length) return;
        try {
            const name = await fetchCharacterName(characters[index]);
            console.log(name);
            processCharacters(index + 1);
        } catch (err) {
            console.error('Error processing character:', err);
            processCharacters(index + 1);
        }
    };

    processCharacters();
});