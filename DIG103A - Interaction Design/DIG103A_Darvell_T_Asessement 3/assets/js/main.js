/*==================== SHOW MENU ====================*/
const navMenu = document.getElementById('nav-menu'),
      navToggle = document.getElementById('nav-toggle'),
      navClose = document.getElementById('nav-close');

/*===== MENU SHOW =====*/
if (navToggle){
          navToggle.addEventListener('click', () => {
              navMenu.classList.add('show-menu')
          })
      };

/*===== MENU HIDDEN =====*/
if (navClose){
    navClose.addEventListener('click', () => {
        navMenu.classList.remove('show-menu')
    })
};

/*==================== REMOVE MENU MOBILE ====================*/
const navLink = document.querySelectorAll('.nav__link');

const linkAction = () => {
    const navMenu = document.getElementById('nav-menu')
    // WHen we click on nav__link, remove show-menu class
    navMenu.classList.remove('show-menu')
};
navLink.forEach(n => n.addEventListener('click', linkAction));


/*==================== SCROLLER ====================*/
const scrollers = document.querySelectorAll(".scroller");

if (!window.matchMedia("(prefers-reduced-motion: reduce)").matches) {
  addAnimation();
};


function addAnimation() {
  scrollers.forEach((scroller) => {
    scroller.setAttribute("data-animated", true);

    const scrollerInner = scroller.querySelector(".scroller__inner");
    const scrollerContent = Array.from(scrollerInner.children);

    scrollerContent.forEach((item) => {
      const duplicatedItem = item.cloneNode(true);
      duplicatedItem.setAttribute("aria-hidden", true);
      scrollerInner.appendChild(duplicatedItem);
    });
  });
};
// If delay in loading elements, wrap AddAnimation into event listener.
document.addEventListener("DOMContentLoaded", function() {
    addAnimation();
});

/* ==================== ABOUT THE ARTISTS ====================*/
const testimonials = document.querySelectorAll('.artists-info');
const navItems = document.querySelectorAll('.artists-item');
const prevArrow = document.querySelector('.artists-arrow.prev');
const nextArrow = document.querySelector('.artists-arrow.next');
const artistsItems = document.querySelector('.artists-items');

let currentIndex = 0;
const totalCount = testimonials.length;
const itemsToShow = 10;
const itemWidth = navItems[0].offsetWidth + 2; // Add margin/padding if needed

function showTestimonial(index) {
  testimonials.forEach(testimonial => {
    testimonial.classList.remove('active');
  });
  testimonials[index].classList.add('active');

  navItems.forEach(navItem => {
    navItem.classList.remove('active');
  });
  navItems[index].classList.add('active');

  const startIndex = Math.max(0, index - Math.floor(itemsToShow / 2));
  const endIndex = Math.min(totalCount, startIndex + itemsToShow);

  artistsItems.innerHTML = '';
  for (let i = startIndex; i < endIndex; i++) {
    const item = navItems[i % totalCount].cloneNode(true);
    item.addEventListener('click', () => showTestimonial(i % totalCount));
    artistsItems.appendChild(item);
  }
}

navItems.forEach((navItem, index) => {
  navItem.addEventListener('click', () => {
    currentIndex = index;
    showTestimonial(currentIndex);
  });
});

prevArrow.addEventListener('click', () => {
  currentIndex = (currentIndex - 1 + totalCount) % totalCount;
  showTestimonial(currentIndex);
});

nextArrow.addEventListener('click', () => {
  currentIndex = (currentIndex + 1) % totalCount;
  showTestimonial(currentIndex);
});

showTestimonial(currentIndex);

/*=============== SHOW SCROLL UP ===============*/ 
const scrollUp = () =>{
	const scrollUp = document.getElementById('scroll-up')
    // When the scroll is higher than 350 viewport height, add the show-scroll class to the a tag with the scrollup class
	this.scrollY >= 350 ? scrollUp.classList.add('show-scroll')
						: scrollUp.classList.remove('show-scroll')
}
window.addEventListener('scroll', scrollUp);