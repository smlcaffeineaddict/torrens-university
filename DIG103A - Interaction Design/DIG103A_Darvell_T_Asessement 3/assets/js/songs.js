// Song data
const songs = [
    {
      name: "Colonia Dignidad",
      artist: "Oscar Mulero",
      path: "assets/music/song/oscar-mulero/ Colonia Dignidad.mp3",
      trackArt: "assets/music/cover/oscar-mulero/colonia dignidad.jpg",
      duration: "5:17",
      genre: "alternative"
    },
    {
      name: "Spaskik",
      artist: "Richie Hawtin",
      path: "assets/music/song/richie-hawtin/Plastikman - Spastik.mp3",
      trackArt: "assets/music/cover/richie-hawtin/spaskik.jpg",
      duration: "9:18", 
      genre: "alternative"
    },
    {
      name: "Spirit",
      artist: "Surgeon",
      path: " assets/music/song/surgeon/Surgeon - Doctot.mp3",
      trackArt: "assets/music/cover/surgeon/spirit.jpg",
      duration: "11:07", 
      genre: "alternative"
    },
    {
      name: "Aire Silencioso",
      artist: "Oscar Mulero",
      path: "assets/music/song/oscar-mulero/Aire Silencioso.mp3",
      trackArt: "assets/music/cover/oscar-mulero/flujo-fatal.jpg",
      duration: "5:17",
      genre: "alternative"
    },
    {
      name: "The Greatest Dancer",
      artist: "Robert Hood",
      path: "assets/music/song/robert-hood/Robert Hood - The Greatest Dancer.mp3",
      trackArt: "assets/music/cover/robert-hood/Robert Hood - The Greatest Dancer.jpg",
      duration: "5:37", 
      genre: "alternative"
    },
    {
        name: "Flujo Fatal",
        artist: "Oscar Mulero",
        path: "assets/music/song/oscar-mulero/Flujo Fatal (Original mix).mp3",
        trackArt: "assets/music/cover/oscar-mulero/flujo-fatal.jpg",
        duration: "5:23",
        genre: "alternative"
    },
    {
      name: "The Tunnel",
      artist: "Richie Hawtin",
      path: "assets/music/song/richie-hawtin/The Tunnel.mp3",
      trackArt: "assets/music/cover/richie-hawtin/the-tunnel.jpg",
      duration: "8:29",
      genre: "alternative"
    },
    {
        name: "Figures of Light",
        artist: "Oscar Mulero",
        path: "assets/music/song/oscar-mulero/Figures of Light.mp3",
        trackArt: "assets/music/cover/oscar-mulero/figures-of-light.jpeg",
        duration: "5:42",
        genre: "alternative"
      },
      {
        name: "Konception",
        artist: "Richie Hawtin",
        path: "assets/music/song/richie-hawtin/Konception.mp3",
        trackArt: "assets/music/cover/richie-hawtin/konception.jpg",
        duration: "7:29", 
        genre: "alternative"
      },
      {
        name: "Chroma Light",
        artist: "Robert Hood",
        path: "assets/music/song/robert-hood/Robert Hood - Chroma Light.mp3",
        trackArt: "assets/music/cover/robert-hood/chroma-light.jpeg",
        duration: "5:37", 
        genre: "alternative"
      },
      {
        name: "EXposed",
        artist: "Richie Hawtin",
        path: "assets/music/song/richie-hawtin/Plastikman - EXposed.mp3",
        trackArt: "assets/music/cover/richie-hawtin/exposed.jpg",
        duration: "12:59", 
        genre: "alternative"
      },
      {
        name: "The Call",
        artist: "Robert Hood",
        path: "assets/music/song/oscar-mulero/Figures of Light.mp3",
        trackArt: "assets/music/cover/oscar-mulero/figures-of-light.jpeg",
        duration: "5:42",
        genre: "alternative"
      },
      {
        name: "Minus",
        artist: "Robert Hood",
        path: "assets/music/song/richie-hawtin/Konception.mp3",
        trackArt: "assets/music/cover/richie-hawtin/konception.jpg",
        duration: "7:29", 
        genre: "alternative"
      },
      {
        name: "This is Techno",
        artist: "Surgeon",
        path: "assets/music/song/robert-hood/Robert Hood - Chroma Light.mp3",
        trackArt: "assets/music/cover/robert-hood/chroma-light.jpeg",
        duration: "5:37", 
        genre: "alternative"
      },
      {
        name: "Balance",
        artist: "Surgeon",
        path: "assets/music/song/richie-hawtin/Plastikman - EXposed.mp3",
        trackArt: "assets/music/cover/richie-hawtin/exposed.jpg",
        duration: "12:59",
        genre: "alternative"
      },
      {
        name: "Ratterdam",
        artist: "Surgeon",
        path: "assets/music/song/richie-hawtin/Plastikman - EXposed.mp3",
        trackArt: "assets/music/cover/richie-hawtin/exposed.jpg",
        duration: "8:50",
        genre: "alternative"
      },
      {
        name: "Badger Racket",
        artist: "Surgeon",
        path: "assets/music/song/surgeon/Badger_Racket.mp3",
        trackArt: "assets/music/cover/surgeon/surgeon_album.jpg",
        duration: "6:42",
        genre: "techno"
      },
      {
        name: "Break For Peace",
        artist: "Surgeon",
        path: "assets/music/song/surgeon/Break_For_Peace.mp3",
        trackArt: "assets/music/cover/surgeon/surgeon_album.jpg",
        duration: "7:18",
        genre: "techno"
      },
      {
        name: "Nihon",
        artist: "Robert Hood",
        path: "assets/music/song/robert-hood/Nihon.mp3",
        trackArt: "assets/music/cover/robert-hood/robert_hood_album.jpg",
        duration: "7:24",
        genre: "techno"
      },
      {
        name: "Alpha Centauri",
        artist: "Robert Hood",
        path: "assets/music/song/robert-hood/Alpha_Centauri.mp3",
        trackArt: "assets/music/cover/robert-hood/robert_hood_album.jpg",
        duration: "6:11",
        genre: "techno"
      },
      {
        name: "Wandernder Puenktestern",
        artist: "Robert Hood",
        path: "assets/music/song/robert-hood/Wandernder_Puenktestern.mp3",
        trackArt: "assets/music/cover/robert-hood/robert_hood_album.jpg",
        duration: "8:33",
        genre: "techno"
      },
      {
        name: "Spatial Clouds",
        artist: "Robert Hood",
        path: "assets/music/song/robert-hood/Spatial_Clouds.mp3",
        trackArt: "assets/music/cover/robert-hood/robert_hood_album.jpg",
        duration: "5:52",
        genre: "techno"
      },
      {
        name: "Unflug",
        artist: "Robag Wruhme",
        path: "assets/music/song/robag-wruhme/Unflug.mp3",
        trackArt: "assets/music/cover/robag-wruhme/robag_wruhme_album.jpg",
        duration: "7:06",
        genre: "house"
      },
      {
        name: "Kuppfingermassacre",
        artist: "Robag Wruhme",
        path: "assets/music/song/robag-wruhme/Kuppfingermassacre.mp3",
        trackArt: "assets/music/cover/robag-wruhme/robag_wruhme_album.jpg",
        duration: "6:22",
        genre: "house"
      },
      {
        name: "Ausgegraben",
        artist: "Robag Wruhme",
        path: "assets/music/song/robag-wruhme/Ausgegraben.mp3",
        trackArt: "assets/music/cover/robag-wruhme/robag_wruhme_album.jpg",
        duration: "5:48",
        genre: "house"
      },
      {
        name: "Hohenzone",
        artist: "Robag Wruhme",
        path: "assets/music/song/robag-wruhme/Hohenzone.mp3",
        trackArt: "assets/music/cover/robag-wruhme/robag_wruhme_album.jpg",
        duration: "8:12",
        genre: "house"
      },
      {
        name: "Resistor Bro",
        artist: "Oscar Mulero",
        path: "assets/music/song/oscar-mulero/Resistor_Bro.mp3",
        trackArt: "assets/music/cover/oscar-mulero/oscar_mulero_album.jpg",
        duration: "7:42",
        genre: "techno"
      },
      {
        name: "Fuzz Bunker",
        artist: "Oscar Mulero",
        path: "assets/music/song/oscar-mulero/Fuzz_Bunker.mp3",
        trackArt: "assets/music/cover/oscar-mulero/oscar_mulero_album.jpg",
        duration: "6:18",
        genre: "techno"
      },
      {
        name: "Quarry Stack",
        artist: "Oscar Mulero",
        path: "assets/music/song/oscar-mulero/Quarry_Stack.mp3",
        trackArt: "assets/music/cover/oscar-mulero/oscar_mulero_album.jpg",
        duration: "8:05",
        genre: "techno"
      },
      {
        name: "Endor Calisthenic",
        artist: "Oscar Mulero",
        path: "assets/music/song/oscar-mulero/Endor_Calisthenic.mp3",
        trackArt: "assets/music/cover/oscar-mulero/oscar_mulero_album.jpg",
        duration: "7:32",
        genre: "techno"
      },
      {
        name: "Can You Feel It",
        artist: "Larry Heard",
        path: "assets/music/song/larry-heard/Can_You_Feel_It.mp3",
        trackArt: "assets/music/cover/larry-heard/larry_heard_album.jpg",
        duration: "6:28",
        genre: "house"
      },
      {
        name: "Washing Machine",
        artist: "Larry Heard",
        path: "assets/music/song/larry-heard/Washing_Machine.mp3",
        trackArt: "assets/music/cover/larry-heard/larry_heard_album.jpg",
        duration: "5:14",
        genre: "house"
      },
      {
        name: "Cosmic Wind",
        artist: "Larry Heard",
        path: "assets/music/song/larry-heard/Cosmic_Wind.mp3",
        trackArt: "assets/music/cover/larry-heard/larry_heard_album.jpg",
        duration: "7:49",
        genre: "house"
      },
      {
        name: "Beyond The Clouds",
        artist: "Larry Heard",
        path: "assets/music/song/larry-heard/Beyond_The_Clouds.mp3",
        trackArt: "assets/music/cover/larry-heard/larry_heard_album.jpg",
        duration: "8:22",
        genre: "house"
      },
      {
        name: "Spiritual Uplifter",
        artist: "Dax J",
        path: "assets/music/song/dax-j/Spiritual_Uplifter.mp3",
        trackArt: "assets/music/cover/dax-j/dax_j_album.jpg",
        duration: "6:03",
        genre: "techno"
      },
      {
        name: "Zephyr",
        artist: "Dax J",
        path: "assets/music/song/dax-j/Zephyr.mp3",
        trackArt: "assets/music/cover/dax-j/dax_j_album.jpg",
        duration: "7:28",
        genre: "techno"
      },
      {
        name: "Cimmerian Twilight",
        artist: "Dax J",
        path: "assets/music/song/dax-j/Cimmerian_Twilight.mp3",
        trackArt: "assets/music/cover/dax-j/dax_j_album.jpg",
        duration: "8:41",
        genre: "techno"
      },
      {
        name: "Lunar Sunrise",
        artist: "Dax J",
        path: "assets/music/song/dax-j/Lunar_Sunrise.mp3",
        trackArt: "assets/music/cover/dax-j/dax_j_album.jpg",
        duration: "6:19",
        genre: "techno"
      },
      {
        name: "Phantom Voices",
        artist: "Luke Slater",
        path: "assets/music/song/luke-slater/Phantom_Voices.mp3",
        trackArt: "assets/music/cover/luke-slater/luke_slater_album.jpg",
        duration: "7:52",
        genre: "techno"
      },
      {
        name: "Planetary Assault Systems",
        artist: "Luke Slater",
        path: "assets/music/song/luke-slater/Planetary_Assault_Systems.mp3",
        trackArt: "assets/music/cover/luke-slater/luke_slater_album.jpg",
        duration: "6:37",
        genre: "techno"
      },
      {
        name: "Underflow",
        artist: "Luke Slater",
        path: "assets/music/song/luke-slater/Underflow.mp3",
        trackArt: "assets/music/cover/luke-slater/luke_slater_album.jpg",
        duration: "8:14",
        genre: "techno"
      },
      {
        name: "Torn Worlds",
        artist: "Luke Slater",
        path: "assets/music/song/luke-slater/Torn_Worlds.mp3",
        trackArt: "assets/music/cover/luke-slater/luke_slater_album.jpg",
        duration: "7:03",
        genre: "techno"
      },
      {
        name: "Your Only Friend",
        artist: "Phuture",
        path: "assets/music/song/phuture/Your_Only_Friend.mp3",
        trackArt: "assets/music/cover/phuture/phuture_album.jpg",
        duration: "5:28",
        genre: "acid house"
      },
      {
        name: "Acid Tracks",
        artist: "Phuture",
        path: "assets/music/song/phuture/Acid_Tracks.mp3",
        trackArt: "assets/music/cover/phuture/phuture_album.jpg",
        duration: "7:16",
        genre: "acid house"
      },
      {
        name: "Slam Dance",
        artist: "Phuture",
        path: "assets/music/song/phuture/Slam_Dance.mp3",
        trackArt: "assets/music/cover/phuture/phuture_album.jpg",
        duration: "6:43",
        genre: "acid house"
      },
      {
        name: "We Are Phuture",
        artist: "Phuture",
        path: "assets/music/song/phuture/We_Are_Phuture.mp3",
        trackArt: "assets/music/cover/phuture/phuture_album.jpg",
        duration: "8:09",
        genre: "acid house"
      },
      {
        name: "Mentasm",
        artist: "Joey Beltram",
        path: "assets/music/song/joey-beltram/Mentasm.mp3",
        trackArt: "assets/music/cover/joey-beltram/joey_beltram_album.jpg",
        duration: "7:21",
        genre: "techno"
      },
      {
        name: "Energy Flash",
        artist: "Joey Beltram",
        path: "assets/music/song/joey-beltram/Energy_Flash.mp3",
        trackArt: "assets/music/cover/joey-beltram/joey_beltram_album.jpg",
        duration: "5:47",
        genre: "techno"
      },
      {
        name: "素晴らしい日々",
        artist: "Joey Beltram",
        path: "assets/music/song/joey-beltram/素晴らしい日々.mp3",
        trackArt: "assets/music/cover/joey-beltram/joey_beltram_album.jpg",
        duration: "6:32",
        genre: "techno"
      },
      {
        name: "Cyclonic Tracker",
        artist: "Joey Beltram",
        path: "assets/music/song/joey-beltram/Cyclonic_Tracker.mp3",
        trackArt: "assets/music/cover/joey-beltram/joey_beltram_album.jpg",
        duration: "8:15",
        genre: "techno"
      },
      {
        name: "Mentasm",
        artist: "Joey Beltram",
        path: "assets/music/song/joey-beltram/Mentasm.mp3",
        trackArt: "assets/music/cover/joey-beltram/joey_beltram_album.jpg",
        duration: "7:21",
        genre: "techno"
      },
      {
        name: "Energy Flash",
        artist: "Joey Beltram",
        path: "assets/music/song/joey-beltram/Energy_Flash.mp3",
        trackArt: "assets/music/cover/joey-beltram/joey_beltram_album.jpg",
        duration: "5:47",
        genre: "techno"
      },
      {
        name: "素晴らしい日々",
        artist: "Joey Beltram",
        path: "assets/music/song/joey-beltram/素晴らしい日々.mp3",
        trackArt: "assets/music/cover/joey-beltram/joey_beltram_album.jpg",
        duration: "6:32",
        genre: "techno"
      },
      {
        name: "Cyclonic Tracker",
        artist: "Joey Beltram",
        path: "assets/music/song/joey-beltram/Cyclonic_Tracker.mp3",
        trackArt: "assets/music/cover/joey-beltram/joey_beltram_album.jpg",
        duration: "8:15",
        genre: "techno"
      },
      {
        name: "Gantz Graf",
        artist: "Autechre",
        path: "assets/music/song/autechre/Gantz_Graf.mp3",
        trackArt: "assets/music/cover/autechre/autechre_album.jpg",
        duration: "7:09",
        genre: "idm"
      },
      {
        name: "Perlence Subrange 6-36",
        artist: "Autechre",
        path: "assets/music/song/autechre/Perlence_Subrange_6-36.mp3",
        trackArt: "assets/music/cover/autechre/autechre_album.jpg",
        duration: "6:24",
        genre: "idm"
      },
      {
        name: "Sublimit",
        artist: "Autechre",
        path: "assets/music/song/autechre/Sublimit.mp3",
        trackArt: "assets/music/cover/autechre/autechre_album.jpg",
        duration: "8:32",
        genre: "idm"
      },
      {
        name: "Augmatic Disport",
        artist: "Autechre",
        path: "assets/music/song/autechre/Augmatic_Disport.mp3",
        trackArt: "assets/music/cover/autechre/autechre_album.jpg",
        duration: "5:51",
        genre: "idm"
      },
      {
        name: "Naundrop",
        artist: "Legowelt",
        path: "assets/music/song/legowelt/Naundrop.mp3",
        trackArt: "assets/music/cover/legowelt/legowelt_album.jpg",
        duration: "6:17",
        genre: "techno"
      },
      {
        name: "Panatropic Orbit",
        artist: "Legowelt",
        path: "assets/music/song/legowelt/Panatropic_Orbit.mp3",
        trackArt: "assets/music/cover/legowelt/legowelt_album.jpg",
        duration: "7:43",
        genre: "techno"
      },
      {
        name: "Unconventional Strakker",
        artist: "Legowelt",
        path: "assets/music/song/legowelt/Unconventional_Strakker.mp3",
        trackArt: "assets/music/cover/legowelt/legowelt_album.jpg",
        duration: "8:26",
        genre: "techno"
      },
      {
        name: "Duskmarine",
        artist: "Legowelt",
        path: "assets/music/song/legowelt/Duskmarine.mp3",
        trackArt: "assets/music/cover/legowelt/legowelt_album.jpg",
        duration: "5:09",
        genre: "techno"
      },
      {
        name: "Ghetto Kraviz",
        artist: "Nina Kraviz",
        path: "assets/music/song/nina-kraviz/Ghetto_Kraviz.mp3",
        trackArt: "assets/music/cover/nina-kraviz/nina_kraviz_album.jpg",
        duration: "7:28",
        genre: "techno"
      },
      {
        name: "Miditerranica",
        artist: "Nina Kraviz",
        path: "assets/music/song/nina-kraviz/Miditerranica.mp3",
        trackArt: "assets/music/cover/nina-kraviz/nina_kraviz_album.jpg",
        duration: "6:51",
        genre: "techno"
      },
      {
        name: "Skyscrapers",
        artist: "Nina Kraviz",
        path: "assets/music/song/nina-kraviz/Skyscrapers.mp3",
        trackArt: "assets/music/cover/nina-kraviz/nina_kraviz_album.jpg",
        duration: "8:14",
        genre: "techno"
      },
      {
        name: "Fury Road",
        artist: "Nina Kraviz",
        path: "assets/music/song/nina-kraviz/Fury_Road.mp3",
        trackArt: "assets/music/cover/nina-kraviz/nina_kraviz_album.jpg",
        duration: "7:07",
        genre: "techno"
      },
      {
        name: "Fatma's Renaissance",
        artist: "KiNK",
        path: "assets/music/song/kink/Fatmas_Renaissance.mp3",
        trackArt: "assets/music/cover/kink/kink_album.jpg",
        duration: "6:22",
        genre: "house"
      },
      {
        name: "Pogo",
        artist: "KiNK",
        path: "assets/music/song/kink/Pogo.mp3",
        trackArt: "assets/music/cover/kink/kink_album.jpg",
        duration: "5:38",
        genre: "house"
      },
      {
        name: "Cloud City Shuffle",
        artist: "KiNK",
        path: "assets/music/song/kink/Cloud_City_Shuffle.mp3",
        trackArt: "assets/music/cover/kink/kink_album.jpg",
        duration: "7:49",
        genre: "house"
      },
      {
        name: "Obtuse Triangle Banger",
        artist: "KiNK",
        path: "assets/music/song/kink/Obtuse_Triangle_Banger.mp3",
        trackArt: "assets/music/cover/kink/kink_album.jpg",
        duration: "8:03",
        genre: "house"
      },
      {
        name: "Workin' Gurl",
        artist: "Honey Dijon",
        path: "assets/music/song/honey-dijon/Workin_Gurl.mp3",
        trackArt: "assets/music/cover/honey-dijon/honey_dijon_album.jpg",
        duration: "6:41",
        genre: "house"
      },
      {
        name: "Downtown",
        artist: "Honey Dijon",
        path: "assets/music/song/honey-dijon/Downtown.mp3",
        trackArt: "assets/music/cover/honey-dijon/honey_dijon_album.jpg",
        duration: "7:18",
        genre: "house"
        },
        {
        name: "Burn Me Up",
        artist: "Honey Dijon",
        path: "assets/music/song/honey-dijon/Burn_Me_Up.mp3",
        trackArt: "assets/music/cover/honey-dijon/honey_dijon_album.jpg",
        duration: "5:52",
        genre: "house"
        },
        {
        name: "Thunda Thighs",
        artist: "Honey Dijon",
        path: "assets/music/song/honey-dijon/Thunda_Thighs.mp3",
        trackArt: "assets/music/cover/honey-dijon/honey_dijon_album.jpg",
        duration: "8:27",
        genre: "house"
        },
        {
        name: "Particle Reanimator",
        artist: "Rebekah Teasdale",
        path: "assets/music/song/rebekah-teasdale/Particle_Reanimator.mp3",
        trackArt: "assets/music/cover/rebekah-teasdale/rebekah_teasdale_album.jpg",
        duration: "7:14",
        genre: "techno"
        },
        {
        name: "Hypersonic Rhythm",
        artist: "Rebekah Teasdale",
        path: "assets/music/song/rebekah-teasdale/Hypersonic_Rhythm.mp3",
        trackArt: "assets/music/cover/rebekah-teasdale/rebekah_teasdale_album.jpg",
        duration: "6:38",
        genre: "techno"
        },
        {
        name: "Nebula Dynamics",
        artist: "Rebekah Teasdale",
        path: "assets/music/song/rebekah-teasdale/Nebula_Dynamics.mp3",
        trackArt: "assets/music/cover/rebekah-teasdale/rebekah_teasdale_album.jpg",
        duration: "8:49",
        genre: "techno"
        },
        {
        name: "Quantum Shift",
        artist: "Rebekah Teasdale",
        path: "assets/music/song/rebekah-teasdale/Quantum_Shift.mp3",
        trackArt: "assets/music/cover/rebekah-teasdale/rebekah_teasdale_album.jpg",
        duration: "7:31",
        genre: "techno"
        }
  ];


/* Songs

Oscar Mulero:
https://www.youtube.com/watch?v=_e3n_zqfOuA 
https://www.youtube.com/watch?v=4XYohGojL8w 
https://www.youtube.com/watch?v=kaXUJeo1HGs
https://www.youtube.com/watch?v=Dhv45uPmq20


Richie Hawtin:
https://www.youtube.com/watch?v=6TYsOMYaz6E
https://www.youtube.com/watch?v=OEpedLxJ4io
https://www.youtube.com/watch?v=ToYhFzVcJP8
https://www.youtube.com/watch?v=txVvReGPP5g


Robert Hood:
https://www.youtube.com/watch?v=rrN2sGQlpds
https://www.youtube.com/watch?v=j-CiUUfmcoI

*/