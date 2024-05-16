let audioPlayer = new Audio();

// Function to update the artist-specific track list
function updateArtistUI(artistName, artistSongs) {
    const trackList = document.getElementById(`${artistName}-track-list`);
    trackList.classList.add(`track-list-container`);
    trackList.innerHTML = "";
  
    artistSongs.forEach((song, index) => {
      const listItem = document.createElement("li");
      listItem.classList.add("specific-track__item");
  
      listItem.addEventListener("click", () => {
        currentSong = index;
        playpauseTrack(artistName, artistSongs);
      });
  
      const trackNumberElement = document.createElement("span");
      trackNumberElement.classList.add("track__number");
  
      if (index === currentSong) {
        const playPauseButton = document.createElement("i");
        playPauseButton.classList.add("track__number", "playpause");
        if (isPlaying) {
          playPauseButton.classList.add("ri-pause-large-fill");
        } else {
          playPauseButton.classList.add("ri-play-large-fill");
        }
        listItem.appendChild(playPauseButton);
      } else {
        trackNumberElement.textContent = index + 1;
        listItem.appendChild(trackNumberElement);
      }
  
      const outerDiv = document.createElement("div");
      outerDiv.classList.add("track__info");
  
      const trackName = document.createElement("span");
      trackName.classList.add("track__name");
      trackName.textContent = `${song.name}`;

      outerDiv.appendChild(trackName);
  
      listItem.appendChild(outerDiv);
  
      const trackDuration = document.createElement("span");
      trackDuration.classList.add("track__duration");
      trackDuration.textContent = song.duration;
      listItem.appendChild(trackDuration);
  
      trackList.appendChild(listItem);
    });
  }
  
  function playpauseTrack(artistName, artistSongs) {
    if (isPlaying) {
      audioPlayer.pause();
      isPlaying = false;
    } else {
      audioPlayer.src = artistSongs[currentSong].path;
      audioPlayer.play();
      isPlaying = true;
    }
    updateArtistUI(artistName, artistSongs);
  }
  
  // Artist 1 (Oscar Mulero)
const artist1 = "oscar-mulero";
const artist1Songs = songs.filter(song => song.artist === "Oscar Mulero");
updateArtistUI(artist1, artist1Songs);

  // Artist 2 (Richie Hawtin)
const artist2 = "richie-hawtin";
const artist2Songs = songs.filter(song => song.artist === "Richie Hawtin");
updateArtistUI(artist2, artist2Songs);

// Artist 3 (Robert Hood)
const artist3 = "robert-hood";
const artist3Songs = songs.filter(song => song.artist === "Robert Hood");
updateArtistUI(artist3, artist3Songs);
  
// Artist 4 (Surgeon)
const artist4 = "surgeon";
const artist4Songs = songs.filter(song => song.artist === "Surgeon");
updateArtistUI(artist4, artist4Songs);

// Artist 5 (Robag Wruhme)
const artist5 = "robag-wruhme";
const artist5Songs = songs.filter(song => song.artist === "Robag Wruhme");
updateArtistUI(artist5, artist5Songs);

// Artist 6 (Larry Heard)
const artist6 = "larry-heard";
const artist6Songs = songs.filter(song => song.artist === "Larry Heard");
updateArtistUI(artist6, artist6Songs);
  
// Artist 7 (Dax J)
const artist7 = "dax-j";
const artist7Songs = songs.filter(song => song.artist === "Dax J");
updateArtistUI(artist7, artist7Songs);

// Artist 8 (Luke Slater)
const artist8 = "luke-slater";
const artist8Songs = songs.filter(song => song.artist === "Luke Slater");
updateArtistUI(artist8, artist8Songs);

// Artist 9 (Phuture)
const artist9 = "phuture";
const artist9Songs = songs.filter(song => song.artist === "Phuture");
updateArtistUI(artist9, artist9Songs);

// Artist 10 (Joey Beltram)
const artist10 = "joey-beltram";
const artist10Songs = songs.filter(song => song.artist === "Joey Beltram");
updateArtistUI(artist10, artist10Songs);

// Artist 11 (Autechre)
const artist11 = "autechre";
const artist11Songs = songs.filter(song => song.artist === "Autechre");
updateArtistUI(artist11, artist11Songs);

// Artist 12 (Legowelt)
const artist12 = "legowelt";
const artist12Songs = songs.filter(song => song.artist === "Legowelt");
updateArtistUI(artist12, artist12Songs);

// Artist 13 (Nina Kraviz)
const artist13 = "nina-kraviz";
const artist13Songs = songs.filter(song => song.artist === "Nina Kraviz");
updateArtistUI(artist13, artist13Songs);

// Artist 14 (KiNK)
const artist14 = "kink";
const artist14Songs = songs.filter(song => song.artist === "KiNK");
updateArtistUI(artist14, artist14Songs);

// Artist 15 (Honey Dijon)
const artist15 = "honey-dijon";
const artist15Songs = songs.filter(song => song.artist === "Honey Dijon");
updateArtistUI(artist15, artist15Songs);

// Artist 15 (Rebekah Teasdale)
const artist16 = "rebekah-teasdale";
const artist16Songs = songs.filter(song => song.artist === "Rebekah Teasdale");
updateArtistUI(artist16, artist16Songs);